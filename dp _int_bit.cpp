//leetcode 97 : interleaving strings============
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true

//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//Output: false

 bool isInterleave(string s1, string s2, string s3) {
        
        int p = s1.size();
        int q= s2.size();
        int r = s3.size();
        if(p+q != r)  //check1:  this check saves some recursive call
            return false;
        vector<vector<int>>dp(p+1 ,vector<int>(q+1,-1));
        
        for(int i=0 ;i<=p ;i++)
        {
            for(int j=0;j<=q ;j++)
            {
                if(i == 0 && j == 0)
                {
                     dp[i][j] = true;
                    continue;
                         
                }
                if( i == 0)
                {
                    dp[i][j] = s2[j-1] == s3[i+j-1] && dp[i][j-1];
                }
                else if( j == 0)
                {
                    dp[i][j] = s1[i-1] == s3[i+j-1] && dp[i-1][j];
                }
                else
                {
                    dp[i][j] = ((s1[i-1] == s3[i+j-1] && dp[i-1][j] )||(s2[j-1] == s3[i+j-1] && dp[i][j-1]));
                }
            }
            
        }
        
            return dp[p][q];
        //return solve(p,q,r,s1,s2,s3,dp);
                                
    }
    //going from ending
    bool solve(int p1,int p2 , int p3,string &s1,string &s2 ,string &s3,vector<vector<int>> &dp)
    {
        if(p1 == 0 && p2 == 0 && p3 == 0)
             return dp[p1][p2] = true;
        
       /* if(p3 == 0 || (p3 !=0  && p1 == 0  && p2 == 0)) //if check1 is  there then we don't need this check
            return dp[p1][p2] = false;*/
        
        if(dp[p1][p2] != -1)
            return dp[p1][p2];
        
        if(p1 == 0)
            return dp[p1][p2] = s2[p2-1] == s3[p3-1] && solve(p1,p2-1,p3-1,s1,s2,s3,dp);
        
        if(p2 == 0)
            return dp[p1][p2] = s1[p1-1] == s3[p3-1] && solve(p1-1 ,p2, p3-1,s1,s2,s3,dp);
        
        if((s1[p1-1] == s3[p3-1] && solve(p1-1 , p2, p3-1 ,s1,s2,s3,dp))||
          s2[p2-1] == s3[p3-1] && solve(p1,p2-1 , p3-1 , s1,s2,s3,dp))
            return dp[p1][p2] = true;
        
        return dp[p1][p2] = false;
    }
    //going form starting
 bool solve(int p1,int p2,int p3 ,string &s1 ,string &s2,string &s3,vector<vector<int>>&dp)
    {
         if(p1 == s1.size() && p2 == s2.size() && p3 == s3.size())
             return true;
        
        if(p3 == s3.size())
            return false;
        if(dp[p1][p2] != -1)
            return dp[p1][p2];
        
        if(p1 == s1.size())
            return dp[p1][p2]=(s2[p2] == s3[p3] && solve(p1,p2+1,p3+1,s1,s2,s3,dp));
        
        if(p2 == s2.size())
            return dp[p1][p2] =(s1[p1] == s3[p3] && solve(p1+1,p2,p3+1,s1,s2,s3,dp));
        
        if((s1[p1] == s3[p3] && solve(p1+1,p2,p3+1,s1,s2,s3,dp))||s2[p2] == s3[p3]&& solve(p1,p2+1,p3+1 , s1,s2,s3,dp))
            return dp[p1][p2]=true;
        
        return dp[p1][p2]=false;
    }
//leetcode 10 :  regular expression matching 

/*Input:
s = "aab"
p = "c*a*b"
Output: true*/

/*Input:
s = "mississippi"
p = "mis*is*p*."
Output: false*/
bool isMatch(string s, string p) {
        
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return isMatch(0,s,0,p,dp);    
    }
    bool isMatch(int i, string& s, int j, string &p,vector<vector<int>>&dp) {
        int pn=p.size(), sn = s.size();
        
        if(j==pn) return i==sn;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p[j+1]=='*') {
            if(isMatch(i,s,j+2,p,dp) || 
               i<sn && (p[j] == '.' || s[i] == p[j]) && isMatch(i+1,s,j,p,dp)) return dp[i][j]=1;
        }
        else if (i<sn && (p[j]=='.'|| s[i]==p[j]) && isMatch(i+1,s,j+1,p,dp)) return dp[i][j]=1;
        return dp[i][j]= 0;
    }
