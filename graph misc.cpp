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
