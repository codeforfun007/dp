//alien dictionary gfg
// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
string findOrder(string dict[], int N, int K) {
    // Your code here
    
    unordered_map<char , vector<char>>ump;
    
    for(int i=0 ;i<N-1 ;i++)
    {
        int size1 = dict[i].size();
        
            int size2 = dict[i+1].size(); // we just need to check adjacent words
            
            for(int s1=0,s2=0;s1<size1&&s2<size2 ;s1++,s2++)
            {
                if(dict[i][s1] != dict[i+1][s2])
                {
                    ump[dict[i][s1]].push_back(dict[i+1][s2]);
                    break; // we have to break as soon as we find the first non-matching character
                }
            }
    }
    
    vector<int>in(26);
    
    for(pair<char , vector<char>>p :ump)
    {
        for(char ch : p.second)
        {
            in[ch-'a']++;
        }
    }
    
    queue<char>q;
    /*for(char ch = 'a' ;ch<= 'z' ;ch += 1)
    {
        if(in[ch] == 0)
        q.push(ch);
    }*/
    for(pair<char , vector<char>>p :ump)
    {
        if(in[p.first -'a'] ==0)
        q.push(p.first);
    }
    
    string ans ="";
    while(!q.empty())
    {
        int size = q.size();
        
        while(size-- >0)
        {
            char cur = q.front();
            
            q.pop();
            
            ans += cur;
            
            for(char t : ump[cur])
            {
                if(--in[t - 'a'] == 0)
                  q.push(t);
            }
        }
    }
    
    return ans;
}

//gfg snake and ladder : minimum "dice throws" to reach destination

#include<bits/stdc++.h>
using namespace std;

int solve(int src , int dest , vector<int>& go)
{
    
    queue<int>q; 
    
    q.push(src); 
    
    int lvl = 0;
    
    int ans = INT_MAX;
    
    vector<bool>vis(31 , false) ; 
    
    while(!q.empty())
    {
        
        int size = q.size();
        
        while(size -- >0)
        {
            int cur= q.front();
            
            q.pop();
            
            if(cur == 30)
             {
            
                return lvl;
             }
             
             vis[cur] =true; //since we can come to one state multiple times so this marking and unmarking of vis can be skipped
            
        
             
            for(int i = 1;i<= 6; i++)
            {
                if(cur+i <= 30 && vis[cur+i] ==false)
                {
                    if(go[cur+i] != -1)  // if there is a snake or ladder at current position
                                         //then don't count this as dice throw and skip to the resulting position
                     q.push(go[cur+i]);
                    
                    else
                     q.push(cur+i );
                }
            }
        }
        
        lvl++;
    }
    
    return -1;
}
int main()
 {
	//code
	
	int t;
	
	cin>>t;
	
	while(t--)
	{
	    int n ;
	    cin>>n;
	    
	    vector<int>go(31 ,-1);
	    for(int i=1 ;i<=n ;i++)
	    {
	        int a,b;
	        cin>>a>>b;
	        
	        go[a] =b;
	    }
	    
	    cout<<solve(1 , 30  ,go)<<endl;
	}
	return 0;
}
 
// bipartite graph : gfg medium level 
bool solve(int src,int G[][MAX] , int V , vector<int>&vis)
{
     queue<int>q;
     
     q.push(src);
     
     int lvl =0;
     
     while(!q.empty())
     {
         int size = q.size();
         
         while(size -->0)
         {
             int cur = q.front();
             
             q.pop();
             
             if(vis[cur] != -1)
             {
                 if(vis[cur] != lvl%2)
                   return false;
                 continue;
             }
             
             vis[cur] = lvl%2;
             
             for(int i = 0 ;i<V;i++)
             {
                 if( G[cur][i] == 1)   
                 {
                     if(cur == i)  //if there is a self loop then it can't be bipartite
			           //the code would have worked fine even without it
			           //provided that vis check is not made at this location
                       return false;
                     q.push(i);
                 }
             }
         }
         lvl++;
     }
     
     return true;
}
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int G[][MAX],int V)
{
     //Your code here 
     vector<int>vis(V ,-1); //-1 signifies as an unvisited vertice
     
     bool res =true;
     for(int i=0;i<V ;i++)
     {
         if(vis[i] == -1)  
         res = res && solve(i,G,V ,vis); //check bipartiteness of each connected component
         
         if(res == false)
           return res;
     }
     
     return true;
}
// =================gfg toptological sort =========================================================

void dfs(int src , vector<int>adj[] ,vector<int>&vis ,vector<int>&ans)
{
    vis[src] = 1;
    
    for(int v : adj[src])
    {
        if(vis[v] == -1)
          dfs(v , adj, vis , ans);
    }
    
    ans.push_back(src);
}

vector<int> bfs(int v,vector<int>adj[])
{
    queue<int>q;
    
    vector<int>in(v ,0);
    
    for(int i=0;i<v ;i++)
    {
        for(int x : adj[i])
        {
            in[x]++;
        }
    }
    
    for(int i=0;i<v ;i++)
    if(in[i] == 0)q.push(i);
    
    vector<int>ans;
    while(!q.empty())
    {
        int size = q.size();
        
        while(size-- >0)
        {
            int cur = q.front();
            
            q.pop();
            
            ans.push_back(cur);
            
            for(int x: adj[cur])
            {
                if(--in[x] == 0)
                 q.push(x);
            }
        }
    }
    
    return ans;
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    
    vector<int>vis(V,-1);
    
    vector<int>ans;
    
    /*for(int i =0 ;i<V ;i++)
    {
        if(vis[i] == -1)
          dfs(i , adj ,vis,ans);
    }
    reverse(ans.begin(),ans.end());*/
    
    ans = bfs(V,adj);
    
    return ans;
}
 //gfg :dijkstra on adjacency matrix
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    
    priority_queue<vector<int> , vector<vector<int>> ,greater<vector<int>>>pq;
    
    pq.push({0,src});  //distance,src;
    
    vector<int>dist(V,0);
    
    vector<int>vis(V ,-1);
    
    while(!pq.empty())
    {
        vector<int> cur = pq.top();
        
        pq.pop();
        
        if(vis[cur[1]] == 1)
          continue;
        
        int vtx = cur[1];
        
        int dis = cur[0];
        
        dist[vtx] =  cur[0];
        
        vis[vtx] = 1;
        
        for(int i = 0;i<V ;i++)
        {
            if(g[vtx][i] != 0 && vis[i] == -1)
              pq.push({ g[vtx][i] + dis,i });
        }
        
        
    }
    return dist;
}
// gfg : minimum steps by knight to reach from given src pos to given tar pos
//constraints
/*1<=T<=100
1<=N<=20   //1 based indexing
1<=knight_pos,targer_pos<=N*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dir = {{-2,1},{-2,-1},{1,-2},{-1,-2},{2,1},{2,-1},{1,2},{-1,2}};
int solve(int s ,int t ,int n)
{
    queue<int>q;
    
    q.push(s);
    
    vector<bool>vis(n*n,false);
    
    int lvl =0 ;
    
    while(!q.empty())
    {
        int size = q.size();
        
        while(size-- >0)
        {
            int cur = q.front();
            
            q.pop();
            
            if(cur == t)
            {
                return lvl;
            }
            
    
             vis[cur] = true;
            
            int r = cur/n;
            
            int c = cur%n;
        
            for(int d = 0;d<dir.size() ;d++)
            {
                int x = r + dir[d][0];
                
                int y = c + dir[d][1];
                
                if(x>=0 && x<n && y>=0 && y<n && vis[x*n+y]== false)
                {
                    vis[x*n+y] = true;
                    q.push(x*n+y);
                }
            }
        }
        lvl++;
    }
    return -1;
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
	    
	     pair<int,int>k;
	     cin>>k.first>>k.second;
	     
	     k.first--; //converting 1 based indexing to 0 based
	     k.second--;
	     
	     int src = k.first*n+k.second;
	     
	     
	     pair<int,int>t;
	     cin>>t.first>>t.second;
	     
	     t.first--;  //converting 1 based indexing to 0 based
	     t.second--;
	     
	     int dest = t.first*n+t.second;
	     
	     cout<<solve(src,dest , n)<<endl;
	}
	return 0;
}
//===gfg : kosarraju algorithm ============
void dfs(int src,vector<bool>& vis,vector<int> adj[],vector<int>&top)
{
    vis[src] = true;
    
    for(int x: adj[src])
    {
        if(vis[x] == false)
          dfs(x,vis,adj,top);
    }
    top.push_back(src);
}

void dfs2(int src , vector<bool>&vis , vector<vector<int>> &rg)
{
    vis[src] = true ; 
    
    for(int x : rg[src])
    {
        if(vis[x] == false)
          dfs2(x,vis,rg);
    }
    
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    
    vector<vector<int>>rg(V);
    
    for(int i=0;i<V ;i++)
    {
        for(int x :adj[i])
        {
            rg[x].push_back(i);
        }
    }
    vector<int>top;
    
    vector<bool>vis(V,false);
    
    for(int i=0 ;i<V ;i++)
    {
        if(vis[i] == false)
         dfs(i,vis,adj,top);
    }
    
    vector<bool>vis2(V,false);
    
    int scc= 0;
    
    for(int i=top.size()-1 ;i>=0 ;i--)
    {
        if(vis2[top[i]] == false)
        {
            dfs2(top[i] ,vis2 ,rg);
            scc++;
        }
    }
    
    return scc;
}
