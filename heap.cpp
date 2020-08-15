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

//leetcode 871 : minimum number of refueling stops 

//0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target
//if this constraint would not been there then we would have sorted the refueling stops
//in increasing order of their distance from starting point
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int mypos = startFuel;
        
        priority_queue<int>pq ;
        
        int stops = 0;
        for(vector<int>v : stations)
        {
            if(v[0] <= mypos)
            {
                pq.push(v[1]);
            }
            else
            {
                if(pq.empty())
                    break;
                
                while(mypos < v[0] && !pq.empty()) //this is an important step
                 //till you not reach the current refueling stop you can not add the 
                 //fuel it has to your priority queue
                {
                    mypos = mypos + pq.top();
                    pq.pop();
                    stops++;
                }
                
                if(mypos <v[0])//if still have not reached the stop then you can not reach the end at all
                    return -1;
                pq.push(v[1]);
            }
        }
        
        while(-1)
        {
            if(mypos >= target || pq.empty())
                break;
            mypos = mypos + pq.top();
            pq.pop();
            stops++;
        }
        if(mypos >= target)
        return stops;
        
        return -1;
    }
};
