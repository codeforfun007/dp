//===gfg matrix multiplication ================================
#include<bits/stdc++.h>
using namespace std;

int solve2(vector<int>& v, vector<vector<int>>&dp)
{
    int n= v.size();
    
    for(int gap =1 ;gap<n;gap++)
    {
        for(int i=0 ,j=gap; j<n;j++,i++)
        {
            if(i+1 == j)
            {
                dp[i][j] = 0;
                continue;
            }
            int omin = INT_MAX;
            for(int cut = i+1 ;cut<j  ;cut++)
            {
                int left = dp[i][cut];
                
                int right = dp[cut][j];
                
                int my = left + v[cut]*v[i]*v[j] + right;
                
                if(my<omin)
                 omin = my;
            }
            
            dp[i][j] = omin;
        }
    }
    return dp[0][n-1];
}
int solve(int si , int ei , vector<int>& v  , vector<vector<int>> &dp)
{
    if(si+1 == ei)
      return 0;

    if(dp[si][ei] != -1)return dp[si][ei] ;
    
    
    int omin = INT_MAX;
    
    for(int cut = si +1  ;cut <ei ;cut++)
    {
        int left = solve(si , cut , v ,dp);
        
        int right = solve(cut , ei , v, dp);
        
        int mycost = left +  v[cut] *v[si]   *v[ei]    + right;
        
        
        if(mycost < omin)
         omin = mycost;
    }
    
    return dp[si][ei] = omin;
}
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    vector<int>v(n,-1);
	    for(int i=0 ;i<n ;i++)
	    cin>>v[i] ;
	    
	    vector<vector<int>>dp(n , vector<int>(n , -1));
	    cout<<solve2(v,dp)<<endl;
	}
	return 0;
}
//========Brackets in Matrix Chain Multiplication =====================
#include<bits/stdc++.h>
using namespace std;

string solve(vector<int>& v)
{
    int n=v.size();
    
    vector<vector<string>>sdp(n , vector<string>(n,""));
    vector<vector<int>>dp(n, vector<int>(n));
    
    for(int gap= 1;gap<n ;gap++)
    {
        for(int si = 0,ei=gap ;ei<n ; si++,ei++)
        {
            if(si+1 == ei)
            {
                dp[si][ei] = 0;
        
                sdp[si][ei] = char(si+'A');  // adding character to string in c++ is complicated
		                             // use s(1, (char)(si + 'A'))
		    continue; // i always forget the base case in tabulation be carefull
            }
            
            int omin=INT_MAX;
            string ans = "";
            
            for(int cut=si+1 ;cut<ei ;cut++)
            {
                int left = dp[si][cut];
                
                int right = dp[cut][ei];
                
                int my = left + v[si]*v[cut]*v[ei] +right;
                
                if(my<omin)
                {
                    omin = my;
                    ans ="(" + sdp[si][cut]+ sdp[cut][ei]+")";
                }
            }
            sdp[si][ei] = ans;
            dp[si][ei] = omin;
        }
    }
    return sdp[0][n-1];
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    vector<int>v(n);
	    for(int i=0 ; i<n ;i++)
	    cin>>v[i];
	    
	    string ans = solve(v);
	    cout<<ans<<endl;
	}
	return 0;
}
====================================================optimal binary search tree========================
#include <bits/stdc++.h>
using namespace std;
int sum(int si , int ei ,vector<int>& f)
{
    int val =0;

    for(int i=si ;i<=ei ;i++)
     val += f[i];
    
    
    return val;
}

void init(vector<int>&pre , vector<int>&f)
{
    for(int i=1 ;i<pre.size() ;i++)
     pre[i] = pre[i-1] + f[i-1];

}
int solve2(vector<vector<int>>& dp , vector<int>& f)
{
    int n= f.size();
    
    vector<int>pre(n+1);
    pre[0] = 0; // 0 is pushed at front of prefix sum array
    
    init(pre,f);
    for(int gap =0 ;gap <n ;gap++ )
    {
        for(int si = 0 ,ei = gap ; ei<n ;si++ ,ei++)
        {
           
            int omin = INT_MAX ; 
            
             
            int my = pre[ei+1] -pre[si];      // dry run this step carefully
            for(int cut = si ; cut<= ei ;cut++)
            {
                int left = si == cut?0:dp[si][cut-1];
                
                int right = cut == ei?0:dp[cut+1][ei];
                
                int mycost = left + my + right;
                
                if(mycost<omin)
                  omin = mycost;
                
            }
            
            dp[si][ei] = omin;
        }
    }
     
    return dp[0][n-1];
}
int solve(int si , int ei , vector<vector<int>>& dp , vector<int>& f)
{
    if(si>ei)
     return 0;
    
    if(dp[si][ei] != -1)
      return dp[si][ei];


    int omin = INT_MAX;
    
    int cur = sum(si , ei , f);
    for(int cut = si ;cut<=ei ;cut++)
    {
        int left = solve(si , cut - 1 , dp , f);
        
        int right = solve(cut+1, ei , dp ,f);
        
        int mycost = left + cur + right;
        
        if(mycost < omin)
        omin = mycost;
    }
    
    return dp[si][ei] = omin;
}
int main() {
    
    vector<int>freq ={ 34 ,8,  50};
    
    int n  = freq.size();
    
    vector<vector<int>>dp(n ,vector<int>(n ,0));
    
    //cout<<solve(0 , freq.size()-1 ,dp , freq)<<endl;
    
    cout<<solve2(dp , freq);
	return 0;
}
//maximum ans minimum values using operators '* and '+'
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long 

ll cal(ll a , ll b ,char op)
{
    switch(op)
    {
        case '+':
        return a+ b;
        case '*':
        return a*b;
    }
    return 1;
}
ll solve(int si, int ei ,int n ,vector<vector<ll>> &dp , string &s)
{
    if(ei >= n || si < 0) 
     return 0;
    
    if(dp[si][ei] != -1)
     return dp[si][ei];
   
   
   ll omax = -1;
    for(int i = si + 1 ; i < ei ;i = i+ 2)
    {
       
       char op = s[i] ;

       ll left = i - 1 > si ? solve(si , i-1 , n , dp , s) : s[i-1] - '0';

       ll right = i + 1 < ei?solve(i+1 , ei, n,dp ,s) : s[i+1] - '0';

       ll my = cal(left ,right , op);
    
       //cout<<my<<"\n";
       if(my > omax)
       omax = my;
    }

    return dp[si][ei] = omax;
}
ll solve_min(int si, int ei ,int n ,vector<vector<ll>> &dp , string &s)
{
    if(ei >= n || si < 0) 
     return 0;
    
    if(dp[si][ei] != -1)
     return dp[si][ei];
   
   
   ll omin = 1e18+ 3;
    for(int i = si + 1 ; i < ei ;i = i+ 2)
    {
       
       char op = s[i] ;

       ll left = i - 1 > si ? solve_min(si , i-1 , n , dp , s) : s[i-1] - '0';

       ll right = i + 1 < ei?solve_min(i+1 , ei, n,dp ,s) : s[i+1] - '0';

       ll my = cal(left ,right , op);
    
       //cout<<my<<"\n";
       if(my < omin)
       omin = my;
    }

    return dp[si][ei] = omin;
}
int main() {
    

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int n = s.length();

        vector<vector<ll>>dp(n , vector<ll>(n ,-1) );
        ll ans = solve( 0 , n-1 , n , dp , s );
        
        /*for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0 ; j<n ;j++)
            {
                cout<<dp[i][j]<<"    ";
            }
            cout<<"\n";
        }*/
        vector<vector<ll>>dp2(n , vector<ll>(n ,-1) );

        ll ans2 = solve_min(0 , n-1 , n , dp2 , s);
        cout<<ans<<" "<<ans2<<endl;
    }
}
