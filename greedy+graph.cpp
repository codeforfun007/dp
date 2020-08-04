//koicost :spoj problem

#include<bits/stdc++.h>
typedef long long  int ll;
using namespace std;
vector<vector<int>>edgelist;
vector<int>par(100005);

vector<int>size(100005);

const int kmod = 1e9;

int find(int u)
{
    if(u == par[u])
    return u;
    
return par[u] = find(par[u]);
}
void solve( ll wtsum)
{
   ll ans = 0;
  for(vector<int>x : edgelist)
  {
      int w = x[0],u = x[1],v = x[2];

       int pu = find(u);
       int pv = find(v);

      if(pu!= pv)
      {
          ans = (ans %kmod + ((1LL)*(size[pu])%kmod * (size[pv])%kmod * (wtsum%kmod))%kmod)%kmod;

          par[pu] = pv;
          
          size[pv] += size[pu];

          find(u);
          
         // wtsum = wtsum - w;
      }
      wtsum = wtsum - w;
  }
  cout<<ans<<endl;
}
void set1()
{


    int v,e;

    cin>>v>>e;
    
    ll wtsum =0;
    for(int i= 1;i<= v ;i++)
      par[i] = i,size[i] = 1;

    for(int i=0;i<e ;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edgelist.push_back({w , a, b});
        wtsum += w;
    }

    sort(edgelist.begin() ,edgelist.end() , [](vector<int>& a ,vector<int>& b)
    {
        return a[0]>b[0];
    });
    solve(wtsum);
}
int main()
{
    set1();
}
