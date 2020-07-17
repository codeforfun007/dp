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
