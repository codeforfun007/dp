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
 
// === leetcode 242  valid anagram i.e. return whether s and t are valid anagrams of each other or not
 bool isAnagram(string s, string t) {
        if(s.size() != t.size())
         return false;
        vector<int>store(26,0);
        
        for(int i=0 ;i<s.size() ;i++)
        {
            store[s[i]-'a']++;
            store[t[i]-'a']--;
        }
        
        for(int i : store)
        if(i != 0 )
            return false;
        
        return true;
 }
