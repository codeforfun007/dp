//=====leetcode 128 longest consecutive sequence ======================

int longestConsecutive(vector<int>& nums) {
        
        
        unordered_set<int>s (begin(nums) , end(nums));
        
        int maxlen =0 ;
        
        for(long x : nums)
        {
            if(s.find(x-1) == s.end())
            {
                int l =0 ;
                
                while(s.find(x++) != s.end())l++;
                
                maxlen = max(maxlen ,l);
            }
        }
        
        return maxlen;
    }
