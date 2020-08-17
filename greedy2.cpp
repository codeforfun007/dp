//this - other for increasing order
//replace - with < for vector
//replace - with > for priority queue

struct comp
{
    public:

    bool operator()(vector<int>&a ,vector<int>& b)
    {
        if(a[0] == b[0]) //if priorities are same then first solve the problem
                         //for lesser rating child
            return a[2]>b[2]; 
        return a[0]>b[0];
    }
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = (int)ratings.size();
        
priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        
        for(int i = 0 ;i< n ;i++)
        {
            int priority = 0;
            
            if(i != 0 && ratings[i] >ratings[i-1])
                priority++;
            if(i != n-1 && ratings[i] >ratings[i+1])
                priority++;
            //priority is 0 for children none of neighbours have lower rating 
            //priority is 1 for children whose one of neighbours have lower rating
            //priority is 2 for children whose both neighbours have lower rating
            pq.push({priority , i , ratings[i]});
        }
        
        vector<int>candy( n , 0);
        
        while(!pq.empty())
        {
            vector<int> cur = pq.top();
            
            pq.pop();
            
            int req = 0; 
            
            int idx =  cur[1];
            
            if(idx != 0 && ratings[idx-1] < ratings[idx])
                req = max(req , candy[idx-1]);
            
            if(idx != n-1 && ratings[idx+1] <ratings[idx])
                req = max(req , candy[idx+1]);
            
            candy[idx] = req + 1;
        }
        
        int ans =  0;
        
        for(int x : candy)
           ans = ans + x;
            
        return ans;
    }
};

//leetcode 948 :bag of tokens
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        
        
        int power = P;
        priority_queue<vector<int> ,vector<vector<int>>,greater<vector<int>>>lpq;
        
        priority_queue<vector<int>>gpq;
        
        int n =(int) tokens.size();
        
        if(n == 0)
            return 0;
        
        vector<int>used( n ,-1);
        
        for(int i = 0;i<n ;i++)
        {
            lpq.push({tokens[i] , i});
            gpq.push({tokens[i] ,i });
        }
        
        int point  = 0;
        int maxpoint  =0 ;
        
        if(lpq.top()[0] > power) //handling base case when power is less than minimum power of token vector
            return 0;
        while(! lpq.empty() )
        {
            vector<int>cur = lpq.top();
            
             lpq.pop();
            
            if(used[cur[1]] != -1)
                continue;
            
            used[cur[1]] = 1;
          
            
           while(power < cur[0] && !gpq.empty())
           {
               vector<int>r = gpq.top();
               
               gpq.pop();
               
               if(used[r[1]] != -1)
                   continue;
               used[r[1]] = 1;
               
               power = power + r[0] ;
               point--;
           }
            
            if(power < cur[0])
                return maxpoint;
            power = power - cur[0];
            point++;
            
            if(point>maxpoint)
                maxpoint = point;
        }
        return maxpoint;
    }
};

//minimum pltforms in a train station problem
#include<bits/stdc++.h>
using namespace std;

int convert(string &a)
{
    
     int t = 0;
     
     t += ( (a[0]-'0')*10)*3600 ;
     
     t +=  (a[1] - '0')*3600;
     
     
     t += ((a[2] - '0')*10)*60 ;
     
     t += (a[3] - '0')*60 ;
    
    //cout<<t<<endl;
    return t;
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
	    
	    string a ;
	    
	    vector<int>arr(n),dep(n);
	    
	    for(int i = 0 ;i<n ;i++)
	    {
	        cin>>a;
	        arr[i] = convert(a);
	    }
	    for(int i = 0 ;i<n ;i++)
	    {
	        cin>>a;
	        dep[i] = convert(a);
	    }
	    
	    sort(arr.begin() ,arr.end());
	    
	    sort(dep.begin() ,dep.end());
	    int i = 1 ,j = 0, req = 1 ,max_req =1 ;
	    
	    while(i < n && j<n)
	    {
	         // If next event in sorted order is arrival, 
            // increment count of platforms needed 
	        if(arr[i]<=dep[j])
	        {
	            i++;
	            req++;
	        }
	         // Else decrement count of platforms needed 
	        else if(arr[i]>dep[j])
	        {
	            j++;
	            req--;
	        }
	        
	       max_req = max(max_req , req);
	    }
	    cout<<max_req<<endl;
	}
	return 0;
}
