 //leetcode  973 k closest points to origin O(nlogk ) solution.
 
 // see the divide and conquer solution on leetcode solution with O(n) complexity
 
// also see the quickselect method given in  most voted commnets on leetcode
 struct comp
    {
      bool operator()(const pair<int,int> &a , const pair<int,int> &b)  
      {
          return sqrt(a.first*a.first + a.second*a.second)<sqrt(b.first*b.first + b.second*b.second);  // max heap implimentation in priority queue '<' is replaced with '>' 
      }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>> , comp>pq;
        
        for(vector<int>p : points)
        {
            pq.push({p[0] ,p[1]});
            
            if(pq.size() >K)
                pq.pop();
        }
        vector<vector<int>>ans ;
        while(pq.size() !=0)
        {
            pair<int,int>x = pq.top();
            ans.push_back({x.first , x.second});
            
            pq.pop();
        }
        
        return ans;
    }
