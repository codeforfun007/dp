// ========decode ways ii  leetcode ============
int numDecodings(string s) {
        
        vector<long>dp(s.size()+1, -1);
        return solve(0 , s , dp);
    }
    const int mod = 1e9+7;
    long solve(int si , string &s ,vector<long>& dp)
    {
        if(si == s.size())
        {
            return dp[si] = 1;
        }
        
        if(dp[si]!=-1)
            return dp[si];
        
        char ch = s[si];
        
        if(ch == '0')
            return dp[si] = 0;
        
        long count  = 0;
        
        if(ch == '*')
        {
            count = (count%mod + (solve(si+1 , s , dp)*9)%mod)%mod;
            
            if(si+1 < s.size())
            {
                char ch2 = s[si+1];
                
                if(ch2 == '*')
                {
                    count = (count%mod + (solve(si+2 , s , dp)*15)%mod)%mod;
            
                }
                else if(ch2 >= '0' && ch2<= '6')
                {
                    count = (count% mod + (solve(si+2,s,dp)*2)%mod)%mod;
                        
                }
                else if(ch2>= '7' && ch2<= '9')
                {
                    count = (count% mod + (solve(si+2,s,dp)*1)%mod)%mod;
                }
            }
        }
            
        else
        {
           count = (count%mod +solve(si + 1 , s , dp)%mod)%mod ;
            
            if(si + 1<s.size())
            {
                char ch2 = s[si+1];
                
                if(ch2 == '*')
                {
                    if(ch == '1')
                    {
                        count =(count%mod+(solve(si+2 ,s ,dp)*9)%mod)%mod;
                    }
                    
                    if(ch == '2')
                    {
                        count =(count%mod+(solve(si+2 ,s, dp)*6)%mod)%mod;
                    }
                }
                else
                {
                    int num = (10*(ch-'0') + ch2 - '0');
                    
                    if(num>= 10 && num<= 26)
                        count = (count %mod + solve(si+2 , s,dp)%mod )%mod;
                }
            }
        }
        return dp[si] = count%mod;
    }
   
==========leetcode 132 palindrome partitioning ii ========
int minCut(string s) {
        
        int n = s.size();
        vector<vector<bool>>is(n,vector<bool>(n,false));
        
        vector<vector<int>>dp(n , vector<int>(n ,-1));
        
        set(is , s);
        
        vector<int>dp2(n , -1);
       // return mincut(0 , n-1 , is , dp , s);
        
        return solve(0, n-1, is , dp2, s);
    }
    
    // it sets the is array as in 
    // if (si,ei) is a palindrome then is[si][ei] = true, otherwise false
    void set(vector<vector<bool>>& is , string &s)
    {
        int n = s.size();
      
         for(int gap=0 ;gap<n ;gap++)
         {
             for(int si=0 , ei= gap ; ei<n ;si++ , ei++)
             {
                 if(gap == 0)
                 {
                     is[si][ei] = true;
                     continue;
                 }
                 
                 if(gap == 1)
                 {
                     is[si][ei] = s[si] == s[ei];
                     continue;
                 }
                 
                 else
                 {
                     is[si][ei] = is[si+1][ei-1] && s[si] == s[ei];
                 }
             }
         }
    }
    //O(n3) time complexity, O(n2) space complexity  , passes 27/29 test cases
    int mincut(int si,int ei,vector<vector<bool>>& is,vector<vector<int>>&dp, string &s)
    {
        if(si == ei || is[si][ei] == true)return dp[si][ei]=0;
        
        if(dp[si][ei]!= -1)return dp[si][ei];
        
        int omin = INT_MAX;
        
        for(int cut = si ; cut <ei ;cut++)
        {
            int left = mincut(si , cut , is,dp ,s);
            
            int right = mincut(cut+ 1 , ei , is, dp ,s);
            
            int my = left + 1 + right;
            
            if(my<omin)
                omin = my;
        }
        
        return dp[si][ei] = omin;
    }
    //O(n2) time complexity , O(n) space complexity , passes all test cases
    int solve(int si , int ei, vector<vector<bool>>&is,vector<int>&dp,string &s)
    {
        if(si == ei || is[si][ei] == true)return dp[si]=0;
        
        if(dp[si] != -1)return dp[si];
        int omin = INT_MAX;
        
        for(int cut = si ; cut<ei ;cut++)
        {
            if(is[si][cut] == true)
            {
                int my = solve(cut+1 , ei, is , dp, s)+1;
                
                if(my<omin)
                    omin = my;
            }
            
        }
        
       return  dp[si]=omin;
    }


//=====leetcode 44 wildcard expression matching ==============

bool isMatch(string s, string p) {
         
        string p2 ="";
    
        set(p2,p);  //converts a pattern string like  "abc**d?f***" into "abc*d?f*"
        
        int n = max(s.size(), p.size());
        
        //vector<vector<int>>dp(n+1 , vector<int>(n +1, -1)); also works
        
        vector<vector<int>>dp(s.size()+1 , vector<int>(p.size()+1 ,-1));
        
        return solve(0 , 0, s , p2 , dp);
    }
    
    int solve(int i , int j , string &s , string & p , vector<vector<int>>&dp)
    
    {
        if(i == s.size() && j == p.size())return dp[i][j] = 1;
        
        if(i == s.size() || j == p.size())
        {
            if(i != s.size())
                return dp[i][j] = 0;
            
            return dp[i][j] = p[j] == '*' &&  j+1 == p.size();  // if j is not reached at the end of pattern 
                                                                //then it will match the pattern only if j is at 
                                                                //last character && the last charater is '*'.
                                                               // we were able to do this because we have handled the case where
                                                              // continuous stars are appearing in pattern.
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        char ch = s[i];
        char ch2 = p[j];
        
        bool res = false;
        if(ch == ch2 || ch2 =='?')
        {
            res = res || solve(i+1 , j+1 , s , p , dp);
        }  
        else if(ch2 == '*')
        {
            res = res || solve(i+1 , j , s , p , dp); //matching the current character with '*
            
            res = res || solve(i , j+1 , s , p , dp); // matching the '*' with empty subsequence
        }
        
        return dp[i][j] = res;
    }
    
    void set(string &p2 , string &p)
    {
        bool first = false;
        
        for(char ch : p)
        {
            if(ch == '*')
            {
                if(first == false)p2 += ch;
                
                first = true;
            }
            else
            {
                p2 += ch;
                
                first = false;
            }
        }
    }
}
