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
