//this - other for increasing order
//replace - with < for vector
//replace - with > for priority queue

struct comp
{
    public:

    bool operator()(vector<int>&a ,vector<int>& b)
    {
        if(a[0] == b[0]) //if priorities are same then first solve the problem
                         //for lesser rating child
            return a[2]>b[2]; 
        return a[0]>b[0];
    }
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = (int)ratings.size();
        
priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        
        for(int i = 0 ;i< n ;i++)
        {
            int priority = 0;
            
            if(i != 0 && ratings[i] >ratings[i-1])
                priority++;
            if(i != n-1 && ratings[i] >ratings[i+1])
                priority++;
            //priority is 0 for children none of neighbours have lower rating 
            //priority is 1 for children whose one of neighbours have lower rating
            //priority is 2 for children whose both neighbours have lower rating
            pq.push({priority , i , ratings[i]});
        }
        
        vector<int>candy( n , 0);
        
        while(!pq.empty())
        {
            vector<int> cur = pq.top();
            
            pq.pop();
            
            int req = 0; 
            
            int idx =  cur[1];
            
            if(idx != 0 && ratings[idx-1] < ratings[idx])
                req = max(req , candy[idx-1]);
            
            if(idx != n-1 && ratings[idx+1] <ratings[idx])
                req = max(req , candy[idx+1]);
            
            candy[idx] = req + 1;
        }
        
        int ans =  0;
        
        for(int x : candy)
           ans = ans + x;
            
        return ans;
    }
};
