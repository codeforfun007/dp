#include <bits/stdc++.h>
using namespace std;

int q_place_per(int qpsf, int tq,string ans, vector<int>&box)
{
    if(tq == qpsf)
    {
        cout<<ans<<endl;
        
        return 1;
    }
    
    int count =0 ;
    
    for(int idx = 0 ;idx<box.size();idx++)
    {
        if(box[idx] == -1)
        {
            box[idx] = 1;
            count += q_place_per(qpsf+1 , tq, ans +"Q" +to_string(qpsf+1)+"->("+to_string(idx)+"),",box);
            box[idx] = -1;
        }
    }
    
    return count;
}

int q_place_comb(int idx,int qpsf, int tq,string ans,vector<int>&box)
{
    if(tq == qpsf)
    {
        cout<<ans<<endl;
        
        return 1;
    }
    
    int count =0 ;
    
    for(int i = idx ;i<box.size();i++)
    {
        
       count += q_place_comb(i+1,qpsf+1 , tq, ans +"Q" +to_string(qpsf+1)+"->("+to_string(i)+"),",box);
           
    }
    
    return count;
}


int q_place_per_2d(int idx,int qpsf , int tq , string ans , vector<vector<int>>&box)
{
    if(qpsf == tq || idx == box.size()*box[0].size())
    {
        if(qpsf == tq)
        {
            cout<<ans<<endl;
        
           return 1;
        }
        return 0;
    }
    
    int count = 0;
    
    int r = idx/box[0].size();
    int c = idx%box[0].size();
    
    if(box[r][c] == -1)
    {
        box[r][c] = 1;
      
        count+= q_place_per_2d(0 , qpsf+1 , tq,ans+"Q"+to_string(qpsf+1)+"->(" +to_string(r) +","+to_string(c)+")"+" " ,box);
        box[r][c] = -1;
    }
    count += q_place_per_2d(idx+1 , qpsf,tq,ans ,box);
    return count;
    
}

int q_place_comb_2d(int idx , int qpsf , int tq,string ans,vector<vector<int>>&box)
{
    if(idx == box.size()*box[0].size() || qpsf == tq)
    {
        if(qpsf == tq)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    
    int count =0;
    
    int r = idx/box[0].size();
    int c = idx%box[0].size();
    
    count += q_place_comb_2d(idx+1 , qpsf+1 , tq,ans+"Q"+to_string(qpsf+1)+"->(" +to_string(r) +","+to_string(c)+")"+" " ,box);

   count += q_place_comb_2d(idx+1,qpsf , tq , ans , box);
   
   return count;
}
void queenplace_set_2d()
{
    vector<vector<int>>box(5,vector<int>(5,-1));
    
    int ans;
    
    //ans = q_place_per_2d(0, 0 , 4 ,"" , box );
    
    ans = q_place_comb_2d(0,0,4,"",box);
    
    cout<<ans;
}

void queenplace_set_1d()
{
    
    vector<int>box(5,-1);
    
    int ans;
    
    //ans = q_place_per(0,3,"",box);
    
    //ans = q_place_comb(0 , 0 ,3,"" ,box);
    
    cout<<ans;
}
int main() {

   //queenplace_set_1d();
    
    queenplace_set_2d();
   
	return 0;
}
