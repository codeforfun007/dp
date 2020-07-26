//hamiltonian path on undirected graph :gfg 
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>vis;

bool dfs_ham(int src,int count)
{
     if(count == vis.size()-1)
    {
        return true;
    }
   
    vis[src] = 1;
    
    bool res = false;
    for(int x:g[src])
    {
        if(vis[x] == -1)
        res =res||dfs_ham(x  , count+1);
    }
    vis[src] = -1;
    return res;
}
/*void dfs_top(int src,vector<int>&ans) //it will be used if the graph is directed 
                                        //then we will traverse through vertices in topological sort  order
                                       
{
     vis[src] = 1;
     
    for(int x:g[src])
    if(vis[x] == -1)
    dfs_top(x , ans);
    
    ans.push_back(src);
}*/
int main()
 {
	//code
	
	int t;cin>>t;
	
	while(t--)
	{
	    int v,e;
	    cin>>v;
	    cin>>e;
	    g.assign(v+1,{});
	    for(int i=0;i<e;i++)
	    {
	        int a,b;
	        cin>>a>>b;
	        
	        g[a].push_back(b);
	        g[b].push_back(a);
	    }
	    
	     bool res = false;
	     vis.assign(v+1,-1);
	     
	     for(int i= 1;i<=v ; i++)
	     {
	         int vtx = i;
	         res = res||dfs_ham(vtx , 1);
	     }
	      cout<<res<<endl;
	}
	return 0;
}
//gfg : scc in case of multiple possible outputs they asked for output which will be given by
//standard implimentation of tarzan's algorithm

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<vector<int>>rg;
vector<bool>vis;

void dfs1(int src,vector<int>&top)
{
    vis[src] = true;
    
    for(int x:g[src])
    {
        if(vis[x] == false)
        dfs1(x,top);
    }
    top.push_back(src);
}

void dfs2(int src,vector<int>&ans)
{
    vis[src] =true;
     ans.push_back(src);
    
    for(int x:rg[src])
    {
        if(vis[x] == false)
        dfs2(x , ans);
    }
   
}
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int v,e;
	    
	    cin>>v>>e;
	    
	     g.assign(v,{});
	    vis.assign(v,false);
	    rg.assign(v,{});
	    
	    for(int i=0;i<e;i++)
	     {
	         int a,b;
	         cin>>a>>b;
	         
	         g[a].push_back(b);
	         rg[b].push_back(a);
	     }
	     
	    vector<int>topsort;
	    for(int i=0;i<v;i++)
	    {
	        if(vis[i] == false)
	        dfs1(i, topsort);
	    }
	    
	    vis.assign(v,false);
	    
	    int scc = 0;
	    vector<vector<int>>ans(v); // max limit of vertices=max limit of sccs
	    for(int i= topsort.size()-1 ;i>=0 ;i--)
	    {
	        int vtx = topsort[i];
	        
	        if(vis[vtx] == false)
	        {
	            dfs2(vtx , ans[scc]);
	            scc++;
	        }
	    }
	    
	    for(int i=0;i<scc ;i++)
	    {
	        for(int j=0;j<ans[i].size();j++)
	        {
	            int x = ans[i][j];
	            cout<<x;
	            if(j+1<ans[i].size())
	            cout<<" ";
	        }
	        cout<<",";
	    }
	    
	    cout<<endl;
	}
	return 0;
}

//see the tarzan's algorihtm to find SCCs.
//it is based on the standard low and in vectors
//we maintain them same for both cases when it is a
//span edge and when it is a back edge as we do in 
//case of bridge
//in that algo we basically find the leader of each scc
//which basically is the root of dfs tree.
//for each vtx in dfs tree we keep on pushing it 
//into the stack. And then we check
//(if low[src] == in[src] )it means that it is head
//of the scc. so we keep popping elements from stack and printing them until
//stack is empty because they are part of same scc as the head(root).



//what is a biconnected component: A graph is biconnected component if there 
//exists a cycle between all pairs of vertices of that graph.
//algorithmically : if the graph is connected and it does not have articulation 
//points it is said to be a biconnected component.

//police chase cses graph algo problem
//passed 7/12 test cases
//see edge connectivity algo on cp algorithms
#include <bits/stdc++.h>
using namespace std;
vector<int>par;


int find(int u)
{
    if( u == par[u])
    return u;
    
    return par[u] = find(par[u]);
}
int main() {
	// your code goes here
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<=n;i++)
	par.push_back(i);
	
	vector<vector<int>>sol;
	int ans= 0 ;
	for(int i=0;i<m ;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    
	    int pu = find(u);
	    int pv = find(v);
	    
	    if(pu != pv)
	    {
	        par[max(pu,pv)] = min(pu ,pv);
	        find(u);
	    }
	    
	    if(par[1]== par[n])
	    {
	        ans++;
	        sol.push_back({u,v});
	        par[pu] = pu;
	        par[u] = pu;
	    }
	}
	
	cout<<ans<<endl;
	
	for(vector<int>a : sol)
	cout<<a[0]<<" "<<a[1]<<endl;
	
	return 0;
}
