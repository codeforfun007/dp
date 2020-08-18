
//O(n^2) solution:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n;
        vector<int>dp(n);
        int omax=-231;
        for(int i=0;i<n ; i++)
        {
            dp[i] = 1;
            
            for(int j=i-1 ; j>=0 ; j--)
            {
              
                if(nums[i]>nums[j] )
                    dp[i] = max(dp[j]+1 , dp[i]);
                 if(omax<dp[i])
                  omax = dp[i];
            }
            
           
        }
        
        return omax;
    }
};

//O(nlogn) solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n;
        vector<int>dp(n);
        int omax=-231;
        for(int i=0;i<n ; i++)
        {
            dp[i] = 1;
            
            for(int j=i-1 ; j>=0 ; j--)
            {
              
                if(nums[i]>nums[j] )
                    dp[i] = max(dp[j]+1 , dp[i]);
                 if(omax<dp[i])
                  omax = dp[i];
            }
            
           
        }
        
        return omax;
    }
};

//leetcode : weighted job scheduling
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>>data(n , vector<int>(3));
        
        for(int i =0; i<n ;i++)
        {
            data[i][0] = startTime[i];
            
            data[i][1] = endTime[i];
            
            data[i][2] = profit[i];
        }
        
        sort(data.begin() , data.end() , [](vector<int>& a ,vector<int>& b)
             {
                 
                 return a[1]<b[1];
             });
        
        vector<int>dp(n);
        
        int omax =0;
         
        dp[0] = data[0][2];
        for(int i = 1;i<n ;i++)
        {
            int include_profit = data[i][2];
            
            int idx = bs(i,data,dp);
            
            if(idx != -1)
             include_profit +=  dp[idx];
            
            // Store maximum of including and excluding 
            dp[i] = max(dp[i-1],include_profit);
        }
        
        return dp[n-1];
    }
    
    // A Binary Search based function to find the latest job 
// (before current job) that doesn't conflict with current 
// job.  "index" is index of the current job.  This function 
// returns -1 if all jobs before index conflict with it. 
// The array jobs[] is sorted in increasing order of finish 
// time. 
    int bs(int jobidx , vector<vector<int>>&data ,vector<int> & dp)
    {
        int l= 0;
        int h = jobidx-1;
        int cur  = data[jobidx][2];
        
        int mp =0 ; 
        
        while(l<=h)
        {
            int m = (l+h)/2;
            
            if(data[m][1]<=data[jobidx][0])
            {
                if(data[m+1][1]<=data[jobidx][0])
                 l = m+1;
                else
                    return m;
            }
            else
                h = m-1;
        }
        
        return -1;
    }
};

//leetcode : russian doll envelopes 
//O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin() , envelopes.end() , [](vector<int>&a ,vector<int>& b)
             {
                 if(a[0] == b[0])
                     return a[1]>b[1];
                 return a[0]<b[0];
             });
        
        int omax =0;
        
        int n = envelopes.size();
        vector<int>dp(n);
        for(int i=0;i<n ; i++)
        {
            dp[i] = 1;
            
            for(int j = i-1 ; j>=0 ;j--)
            {
                if(envelopes[j][1] < envelopes[i][1])
                {
                    dp[i] = max(dp[j]+1 , dp[i]);
                }
            }
            if(omax<dp[i])
                omax = dp[i];
        }
        
        return omax;
    }
};

//O(nlogn)
int maxEnvelopes(vector<pair<int, int>>& envelopes) 
{
	int size = envelopes.size();
	sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int>b){
		return a.first<b.first || (a.first==b.first && a.second>b.second);
	});
	vector<int> collector;
	for(auto& pair: envelopes)
	{
		auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
		if(iter == collector.end()) collector.push_back(pair.second);
		else if(*iter > pair.second) *iter = pair.second;
	}
	return collector.size();
}
