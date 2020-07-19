#include <bits/stdc++.h>
using namespace std;
vector<int>coins = {2,3,5,7};

int cc_per_inf(int idx , string ans,int amount )
{
    if(amount == 0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=0 ;i<coins.size() ;i++)
    {
        if(amount - coins[i]>=0)
        count += cc_per_inf(i , ans + to_string(coins[i]) +", ",amount - coins[i]);
    }
    
    return count;
}

int cc_comb_inf(int idx,string ans ,int amount)
{
    if(amount == 0)
    {
        cout<<ans<<endl;
        return 1;
    }
    
    int count =0;
    
    for(int i=idx ; i<coins.size();i++)
    {
        if(amount - coins[i]>=0)
          count += cc_comb_inf(i , ans + to_string(coins[i]) +", ",amount - coins[i]);
    }
    
    return count;
}
int cc_per_fin(int idx , string ans,int amount ,vector<bool>&vis)
{
    if(amount == 0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=0 ;i<coins.size() ;i++)
    {
        if(amount - coins[i]>=0 && vis[i] == false)
        {
            vis[i] = true;
          count += cc_per_fin(i+1 , ans + to_string(coins[i]) +", ",amount - coins[i],vis);
           vis[i] = false;
        }
        
    }
    
    return count;
}

int cc_comb_fin(int idx,string ans ,int amount)
{
    if(amount == 0)
    {
        cout<<ans<<endl;
        return 1;
    }
    
    int count =0;
    
    for(int i=idx ; i<coins.size();i++)
    {
        if(amount - coins[i]>=0)
          count += cc_comb_fin(i+1 , ans + to_string(coins[i]) +", ",amount - coins[i]);
    }
    
    return count;
}

int cc_per_inf_sub(int idx , string ans , int amount)
{
    if(amount == 0 || idx == coins.size())
    { 
        if(amount == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    
    int count =0;
    if(amount - coins[idx]>=0)
     count += cc_per_inf_sub(0,ans + to_string(coins[idx]) +" ",amount-coins[idx]);
    
    count += cc_per_inf_sub(idx+1,ans , amount);
    
    return count;
}

int cc_comb_inf_sub(int idx , string ans , int amount)
{
    if(amount == 0 || idx == coins.size())
    { 
        if(amount == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    
    int count =0;
    if(amount - coins[idx]>=0)
     count += cc_comb_inf_sub(idx,ans + to_string(coins[idx]) +" ",amount-coins[idx]);
    
    count += cc_comb_inf_sub(idx+1,ans , amount);
    
    return count;
}
int cc_per_fin_sub(int idx , string ans , int amount,vector<bool>&vis)
{
    if(amount == 0 || idx == coins.size())
    { 
        if(amount == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    
    int count =0;
    if(amount - coins[idx]>=0 && vis[idx] == false)
    {
        vis[idx] = true;
       count += cc_per_fin_sub(0,ans + to_string(coins[idx]) +" ",amount-coins[idx],vis);
       vis[idx] = false;
    }
   
    count += cc_per_fin_sub(idx+1,ans , amount,vis);
    
    return count;
}
int cc_comb_fin_sub(int idx , string ans , int amount)
{
    if(amount == 0 || idx == coins.size())
    { 
        if(amount == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    
    int count =0;
    if(amount - coins[idx]>=0)
     count += cc_comb_fin_sub(idx+1,ans + to_string(coins[idx]) +" ",amount-coins[idx]);
    
    count += cc_comb_fin_sub(idx+1,ans , amount);
    
    return count;
}


void pncset()
{
     //int ans = cc_per_inf(0 , "" , 10) ;
     
     //int ans = cc_comb_inf(0,"",10);
     int ans;
     vector<bool>vis(4,false);
    // ans = cc_per_fin(0,"",10,vis);
    
    //ans = cc_comb_fin(0,"" ,10);
    //ans = cc_per_inf_sub(0 , "" , 10);
    
    //ans = cc_comb_inf_sub(0,"",10);
    
    //ans = cc_per_fin_sub(0,"",10,vis);
     
     ans = cc_comb_fin_sub(0,"",10);
    cout<<ans;
}
int main() {

   pncset();
	return 0;
}
