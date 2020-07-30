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

