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
          ans = (ans %kmod + ((1LL)*(size[pu])%kmod * (size[pv])%kmod * (wtsum%kmod))%kmod)%kmod; //this has to be handled carefully 
                             //without (1LL) it gave the wrong answer

          par[pu] = pv;
          
          size[pv] += size[pu];

          find(u);
          
         // wtsum = wtsum - w;
      }
      wtsum = wtsum - w;  //weight should be decreased at every step
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


//CSES : flight discount gave wrong answer

#include<bits/stdc++.h>
typedef long long  int ll;
using namespace std;
 
vector<vector<int>>g[100005];
 int v,e;
 
void solve()
{
 
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
 
    pq.push({0 , 1 , 0});
 
    vector<bool>vis(v+1 ,false);
 
   ll msf = INT_MIN;
 
   ll overallans= 1e18;
    while(!pq.empty())
    {
        vector<ll> cur = pq.top();
        
        ll vtx = cur[1];
 
        msf = max(cur[2] , msf);
 
        pq.pop();
        if(vtx == v)
        {
            ll ans = cur[0];
 
            ans = ans - msf;
 
            ans = ans + msf/2;
 
            
            overallans = min(overallans , ans);
 
            continue;
        }
 
        if(vis[vtx] == true)
        {
            continue;
        }
        vis[vtx] = true;
 
        for(vector<int> x : g[vtx])
        {
            if(vis[x[0]] == false)
              pq.push({cur[0] + x[1] , x[0] , x[1]});
        }
    }
 
    cout<<overallans<<endl;
}
void set1()
{
 
 
    cin>>v>>e;
    for(int i=0 ;i<e ;i++)
    {
        int a,b,w;
        cin>>a>>b>>w; 
        
        g[a].push_back({b ,w});
    }
    solve();
}
int main()
{
    set1();
}
