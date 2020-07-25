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
