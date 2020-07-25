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
