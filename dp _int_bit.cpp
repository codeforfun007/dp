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

//scramble string leetcode 81 
/*Input: s1 = "abcde", s2 = "caebd"
Output: false*/

/*Below is one possible representation of str = “coder”:

    coder
   /    \
  co    der
 / \    /  \
c   o  d   er
           / \
          e   r
To scramble the string, we may choose any non-leaf node and swap its two children.
Suppose, we choose the node "co" and swap its two children, it produces a scrambled string "ocder".*/

bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
    
    bool solve(string s1,string s2)
    {
        if(s1.empty() && s2.empty())
            return true;
       if(s1 == s2)
           return true;
        
        if(ana(s1,s2) == false)
            return false;
        
        int n = s1.size();
        
        for(int i =1;i<n ;i++)
        {
            if(solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i)))
                return true;
            
            if(solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i)))
                return true;
        }
        
        return false;
    }
    
    bool ana(string &s,string &p)
    {
        if(s.size() != p.size())
            return false;
        vector<int>store(26,0);
        
        for(int i=0;i<s.size();i++)
        {
            store[s[i]-'a']++;
            store[p[i]-'a']--;
        }
        
        for(int i:store)
            if(i != 0)return false;
        
        return true;
    }
//============tushar's birtday bombs problem interview bit=============
vector<int> bday(int R, vector<int>& p) {
	int n = (int)p.size();
	vector<int> dp(R + 1, -1);
	vector<int> back(R + 1);

	back[0] = 0;
	for (int r = 0; r <= R; r++) {
		for (int i = 0; i < n; i++) {
			if (r >= p[i] && dp[r] < dp[r - p[i]] + 1) {
				dp[r] = dp[r - p[i]] + 1;
				back[r] = i;
			}
		}
	}

	vector<int> ans;
	int r = R;
	while (r >= 0 && (r - p[back[r]]) >= 0) {
		ans.push_back(back[r]);
		r = r - p[back[r]];
	}
	return ans;
}
/*The lexicographic constraint is solved by using dp[r] < dp[r - p[i]] + 1 (i.e. use < instead of <=), then for a
specific resistance you save the index of the kick power that gives you the maximum number of kicks
for that resistance (thus, by going backward you generate the steps back). Furthermore, since the kicks 
have to be smaller than the resistance we have to do this while (r >= 0 && (r - p[back[r]]) >= 0) when 
you generate the answer.*/





== // jump game array interview bit===============
bool solve(int si , vector<int>&A ,vector<int>&dp)
{
    if(si == A.size())
      return true;
      
    if(dp[si] != -1)
      return dp[si];
    bool res = false;
    
    for(int jump= 1;jump<=A[si];jump++)
    {
        if(jump+si<= A.size())
        {
            res = res || solve(jump+si,A,dp);
            if(res == true )
             return dp[si]=true;
        }
    }
    
    return dp[si]=false;
}


int Solution::canJump(vector<int> &A) {
    
    if(A.size() == 1)return 1;   //trivial case : had to be handled explicitly
    vector<int>dp(A.size(),-1);
    return solve(0, A,dp);
}


//=====min jump array problem(assuming that there is a possiblity u won't reach the end)

//dry run before implimenting the solution
int Solution::jump(vector<int> &A) {
    
    int n= A.size();
    if(A.size() <= 1)
      return 0;
      
    if(A[0] == 0)
      return -1;
    
    int maxreach = A[0];
    int step = A[0];
    int jump = 1;
    
    for(int i=1;i<n; i++)
    {
        if(i == n-1)
          return jump;
        maxreach = max(maxreach , A[i]+i);
        
        step--;
        
        if(step == 0)
        {
            jump++;
            
            if(i>=maxreach)
              return -1;
            
            step = maxreach - i ;
        }
    }
    return jump;
}
//dp :memoisation solution
int solve(int si ,vector<int>&A , vector<int>&dp)
{
    if(si == (A.size()-1))
      return 0;
      
    if(dp[si] != -1)
       return dp[si];
       
    int omin = INT_MAX;
    
    for(int i=1 ;i<= A[si] ;i++)
    {
        if(si+i < A.size())
        {
            int rec = solve(si+i , A, dp);
            
            if(rec != INT_MAX && rec+1 <omin)
              omin = rec+1;
        }
    }
    return dp[si] = omin;
}
 
int Solution::jump(vector<int> &A) {
    
    if(A.size() == 1 )return 0;
    
    vector<int>dp(A.size(),-1);
    
    int ans = solve(0,A,dp);

    
    return ans  == INT_MAX? -1 :ans ;
}

//=== longest arithmetic progression =====

int Solution::solve(const vector<int> &A) {
    
    int n= A.size();
    unordered_map<int,unordered_map<int,int>>diff; //idx,diff ,length
    int omax =0;
     
    if(n == 1)  //trivial case: had to be handled explicitly
	        //our code manages the cases where n>=2
      return 1;
    
    for(int  i=0;i<n ;i++)
    {
        for(int j=i-1 ;j>=0 ;j--)
        {
            int d = A[i]-A[j];
            
            if(diff[i].find(d) == diff[i].end())
            {
                diff[i][d] = 2;
            }
           
            diff[i][d] = max(diff[j][d]+1,diff[i][d]);
            
            if(omax<diff[i][d])
              omax = diff[i][d];
        }
    }
    
    return omax;
}

//=== increasing path in a matrix=========
//actually the exact question is if there is an increasing path which starts from (0,0) and takes to bottom right corner of matrix
//then return the length of longest such path if there does not exist such path then return -1
  //it is partially accepted solution

//note : we were asked to find the longest increasing path in a matrix starting from any cell
//then it would have been a topological sort(kahn's algo) problem

int solve2(int r,int c ,int rs,int cs , vector<vector<int>>&A,vector<vector<int>>&dp)
{
    //botttom up solution
    for(int r = rs ;r>=0 ;r--)
    {
        for(int c = cs;c>=0 ;c--)
        {
            if(r == rs && c==cs)
            {
                dp[r][c] = 0;
                continue;
            }
            int omax = -231;
    
           if(r+1<=rs && A[r+1][c] >A[r][c])
             {
              int op1 = max(omax,dp[r+1][c]);
              if(op1 != -231 && op1+1>omax)
                 omax = op1 + 1;
             }
             
            if(c+1<=cs && A[r][c+1]>A[r][c])
             {
               int op2 = max(omax,dp[r][c+1]);
               if(op2 != -231 && op2+1>omax)
                 omax = op2+1;
            }
            
            dp[r][c]  = omax;
            
        }
    }
    return dp[0][0];
	
	//top _down solution
    /*if(r == rs && c == cs)
      return dp[r][c] = 0;
    
    if(dp[r][c] != -1)
      return dp[r][c];
    
    
    long int omax = -231;
    
    if(r+1<=rs && A[r+1][c] >A[r][c])
      {
          long int op1 = max(omax,solve2(r+1,c,rs,cs,A,dp));
          if(op1 != -231 && op1+1>omax)
            omax = op1 + 1;
      }
    if(c+1<=cs && A[r][c+1]>A[r][c])
    {
         long int op2 = max(omax,solve2(r,c+1,rs,cs,A,dp));
         if(op2 != -231 && op2+1>omax)
           omax = op2+1;
    }
    return dp[r][c] = omax;*/
}
int Solution::solve(vector<vector<int> > &A) {
    
    
    int  rs = A.size();
    if(rs == 0)
      return 0;
    int  cs = A[0].size();
    if(rs == 1 && cs == 1)  //trivial case
      return 1;
    vector<vector<int>>dp(rs,vector<int>(cs,-1));
    int ans =solve2(0,0,rs-1,cs-1,A,dp);
    
    return ans == -231 ?-1 :ans;
}

// ======leetcode 329 : longest increasing path in a matrix===

int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        
        int m = matrix.size();
        if(m == 0)return 0;
        int n = matrix[0].size();  //trivial case
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        vector<vector<int>>in(m , vector<int>(n,0));
        for(int i=0;i<m ;i++)
        {
            for(int j=0;j<n ;j++)
            {
                int cur = matrix[i][j];
                
                for(int d=0;d<4;d++)
                {
                    int x = i+dir[d][0];
                    int y = j+dir[d][1];
                    
                    if(x>=0 && x<m &&y>=0 && y<n &&matrix[x][y]>matrix[i][j])
                    {
                        in[x][y]++;
                    }
                        
                }
            }
        }
        queue<int>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(in[i][j] == 0)
                    q.push(i*n+j);
            }
        }
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size-- >0)
            {
                int cur = q.front();
                
                
                
                q.pop();
                
                int r = cur/n;
                
                int c = cur%n;
                
                for(int d=0;d<dir.size();d++)
                {
                    int x = r + dir[d][0];
                    
                    int y = c + dir[d][1];
                    if(x>=0&&x<m &&y>=0 &&y<n &&matrix[x][y]>matrix[r][c])
                    {
                        if(--in[x][y] == 0)
                            q.push(x*n+y);
                    }
                }
            }
            level++;
        }
        
        return level;
    }
