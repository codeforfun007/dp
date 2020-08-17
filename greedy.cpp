//activity selection problem :spoj(busy man)
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin>>t;

   while(t--)
   {
       int n;
       cin>>n;

       vector<vector<int>>v;
       for(int i=0;i<n;i++)
       {
           int a,b;
           cin>>a>>b;

           v.push_back({a,b});
       }

       sort(v.begin(),v.end(), [](vector<int>a,vector<int>b)
       {
           return a[1]<b[1];
       });
       int ans =0 ;
       int e = 0;
       for(vector<int> x:v)
       {
           if(e<= x[0])  //if cur starting time is greater than equal to ending time of prev activity
           {
               ans++;
               e = x[1]; //update ending time of activity
           }
       }
       cout<<ans<<endl;
   }
}
int main() {
    solve();
}

//gfg : job sequencing
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n ;
	    cin>>n;
	    
	    vector<vector<int>>job ;
	    
	    for(int i =0 ;i<n ;i++)
	    {
	        int a,b,c;
	        cin>>a>>b>>c;
	        
	        job.push_back({a, b , c});
	    }
	    
	    sort(job.begin() , job.end() ,[] (vector<int>& a ,vector<int>& b)
	    {
	        return a[2]>b[2];
	    }
	    );
	    
	    vector<int>slot(n+1 , -1);
	    //slot[k] : the job whose deadline is k+1
	    
	    for(int a = 0;a< n ;a++)
	    {
	       int deadline = job[a][1] ;
	       
	       for(int i = min(deadline-1 ,n-1); i>=0 ;i--)
	       {
	           if(slot[i] == -1)
	           {
	               slot[i] = a; //storing the index of job at each slot
	               break;
	           }
	       }
	    }
	    int profit  = 0;
	    int act  =0 ;
	    for(int i = 0;i< n ;i++)
	    {
	        if(slot[i] == -1)
	         continue;
	        int idx = slot[i];
	        profit = profit + job[idx][2];
	        act++;
	    }
	    cout<<act<<" "<<profit<<endl;
	}
	return 0;
}

//gfg : fractional knapsack

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,w;
	    cin>>n>>w;
	    
	    vector<vector<int>>items;
	    
	    for(int i = 0 ;i<n ;i++)
	    {
	        int a ,b; 
	        cin>>a>>b;
	        
	        items.push_back({a , b});
	    }
	    
	    sort(items.begin() ,items.end() ,[](vector<int>a ,vector<int>b)
	    {
	        return (1.0 *a[0]/a[1]) > (1.0 * b[0]/b[1]);
	    });
	    
	    double profit =  0.0;
	    
	    for(vector<int> v : items)
	    {
	        if( w >= v[1])
	        {
	            profit = profit + v[0]*1.0;
	            w = w - v[1];
	        }
	        else
	        {
	            profit = profit +(v[0]/(v[1]*1.0))*w ;
	            w = 0;
	            break;
	        }
	    }
	    printf("%.2f\n" ,profit);  //this is the most important step
		//two round up upto two decimal places
		/* 2nd method :
float round(float var) 
{ 
	// 37.66666 * 100 =3766.66 
	// 3766.66 + .5 =3767.16 for rounding off value 
	// then type cast to int so value is 3767 
	// then divided by 100 so the value converted into 37.67 
	float value = (int)(var * 100 + .5); 
	return (float)value / 100; 
} 

int main() 
{ 
	float var = 37.66666; 
	cout << round(var); 
	return 0; 
} */

	}
	return 0;
}
//biased standing :spoj problem sorting solution O(n)
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin>>t;

   while(t--)
   {
       int n;
       cin>>n;

       vector<int>v(n);
       for(int i = 0;i<n; i++)
       {
           string s;
           int a;
           cin>>s>>v[i];
           
       }
       sort(v.begin(),v.end() , [](int a ,int b)
       {
           return a<b;
       });
        long long int badness = 0;  //this was giving the wrong answer
        for(int i=1;i<=n ;i++)
       {
           badness = badness+abs(v[i-1]-i);
       }
      cout<<badness<<endl;
   }
}
int main() {
    solve();
}
//biased standing using priority queue : O(nlongn)

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin>>t;

   while(t--)
   {
       int n;
       cin>>n;

       priority_queue<int,vector<int>,greater<int>>pq;

       for(int i = 0;i<n; i++)
       {
           string s;
           int a;
           cin>>s>>a;
           pq.push(a);
       }
        long long int badness = 0;
        for(int i=1;i<=n ;i++)
       {
           badness = badness+abs(pq.top()-i);
           pq.pop();
       }
      cout<<badness<<endl;
   }
}
int main() {
    solve();
}

//solution using counting sort : O(n)
//since the element range is 1 to n w
//we can therefore apply counting sort

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin>>t;

   while(t--)
   {
       int n;
       cin>>n;

       vector<int>v(n,0);
       for(int i = 0;i<n; i++)
       {
           string s;
           int a;
           cin>>s>>v[i];
           
       }
       vector<int>counting(n+1 ,0);
       for(int i=0;i<n;i++)
        counting[v[i]]++;

       long long int badness = 0;
        for(int i=1,rank =1 ;i<=n ;i++)
        {
            if(counting[i]>0)
            {
                badness +=  abs(rank - i);
                rank++;
                counting[i]--;
                i--;
            }
        }
      cout<<badness<<endl;
   }
}
int main() {
    solve();
}

//spoj : load balancing problem (great problem)
#include<bits/stdc++.h>

using namespace std;
void solve()
{
    
    while(-1)
    {
        int n;
       cin>>n;
       if(n == -1)  //different type of input 
         return;
    vector<int>v(n);
    
    int check =0;
    for(int i=0;i<n;i++)
     cin>>v[i],check += v[i];
    
    if(check % n != 0)
     {
         cout<<"-1"<<endl;
         continue;
     }
    int req_sum = (check/n);
    int sum = 0;
    int min_round_req = 0;
    int ans = 0;

    for(int i = 0;i<n;i++)
    {
        sum += v[i];

        min_round_req = abs(sum - (req_sum)*(i+1));

        ans = max(ans , min_round_req);
    }
    cout<<ans<<endl;
    }
}
int main(){

   solve();

	return 0;
}
//chopsticks problem codechef 
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,d;
    cin>>n>>d;
     
    vector<int>v(n);
    for(int i=0;i<n ;i++)
    cin>>v[i];

    sort(v.begin (), v.end());

    int ans = 0;
    for(int i =0 ;i<(n-1) ;i++)
    {
        int cur = v[i];
        int next = v[i+1];
        if(abs(cur-next)<=(d))  //not taking absolute gave error
        {
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    solve();
}

//codeforces educational 93 D

#include <bits/stdc++.h>



using namespace std;

void solve()
{
    


   int rs,gs,bs;
   cin>>rs>>gs>>bs;

   vector<int>r(rs) ,b(bs),g(gs);
   for(int i= 0 ; i<rs ;i++)
   cin>>r[i];

   for(int i= 0 ; i<gs ;i++)
   cin>>g[i];

   for(int i= 0 ; i<bs ;i++)
   cin>>b[i];

   sort(rbegin(r),rend(r) );
   sort(rbegin(b) ,rend(b));
   sort(rbegin(g) ,rend(g)) ;


   int rp = 0 ,bp = 0,gp = 0;

   long long int ans = 0;

   priority_queue<pair<int ,int>>pq;

   for( ; rp<rs && bp <bs && gp<gs ;) //0 , 1 ,2
   {
      
       pq.push({b[bp] , 1}) ;

       pq.push({g[gp] , 0});

        pq.push({r[rp] , 2});


       pair<int,int> f = pq.top();

       pq.pop();
       pair<int,int> s = pq.top();
       pq.pop();
        
       cout<<f.first<<" "<<s.first<<endl;
       ans = ans + (f.first)*(s.first);
      
      pair<int,int>left = pq.top();
      pq.pop();
      if(left.second == 0)
      {
          rp++;
          bp++;
      }
      else if(left.second == 1)
      {
          rp++;
          gp++;
      }
      else{
           gp++;
          bp++;
         
      }
   }

   if(rp == rs)
   {
       for( ; bp<bs && gp<gs ;bp++ ,gp++ )
       {
           ans = ans + b[bp]*g[gp] ;
       }
   }
    if(bp == bs)
   {
       for( ; rp<rs && gp<gs ;rp++ ,gp++ )
       {
           ans = ans + r[rp]*g[gp] ;
       }
   }
    if(gp == gs)
   {
       for( ; bp<bs && rp<rs ; bp++,rp++)
       {
           ans = ans + b[bp]*r[rp] ;
       }
   }

   cout<<ans<<endl;
}
int main() {
   

   solve();
}

