class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        if(n<=1)return n;
        
        vector<int>tail(n);
        
        tail[0] = nums[0];
        
        int len = 1;
        
        for(int i=1 ;i<n ;i++)
        {
            if(tail[len-1]<nums[i])
            {
                tail[len] = nums[i];
                
                len++;
            }
            else
            {
                int idx = bsc(tail,len,nums[i]);
                
                tail[idx] = nums[i];
            }
        }
        return len;
    }
    
    int bsc(vector<int>&tail , int len , int val)
    {
        int l =0 ;
        
        int h =len -1 ;
        
        int res;
        while(l<=h)
        {
            int m = (l+h)/2;
            
            if(tail[m] == val)
                return m;
            
            else if(tail[m]>val)
            {
                res = m;
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        
        return res;
    }
};
