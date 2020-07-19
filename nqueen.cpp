//nqueen leetcode :return all the distinct solutions

//==method i :got TLE======== A C = 7/9

vector<vector<string>>sol;
    vector<vector<string>> solveNQueens(int n) {
        
      
        vector<string>box(n,string(n,'.'));
        
         q_place_comb(0 , 0 ,n ,box);
        
        return sol;
    }
    
     vector<vector<int>>dir = {{0,-1} ,{-1,0} ,{1,0} ,{0,1},{-1,1},{1,-1},{1,1},{-1,-1}};
    bool canplace(int &r ,int &c,vector<string>& box)
    {
       
        
        for(int d = 0;d<dir.size() ;d++)
        {
            for(int mag = 1;mag<box.size() ;mag++)
            {
                int x = r + mag*dir[d][0];
                int y = c + mag*dir[d][1];
                
                if(x>=0 && x<box.size() && y>=0 && y<box.size())
                {
                    if(box[x][y] == 'Q')
                        return false;
                }
                else
                    break;
            }
        }
        return true;
    }
    void q_place_comb(int idx , int qpsf , int n ,vector<string>& box)
    {
        if(idx == n*n || qpsf == n)
        {
            if(qpsf == n)
            {
                sol.push_back(box);
                
                return;
            }
            return;
        }
        
        int r = idx/n;
        
        int c = idx%n;
        
        if(canplace(r,c,box))
        {
            box[r][c] = 'Q';
            q_place_comb(idx+1 , qpsf+1 , n,box );
            box[r][c] = '.';
        }
        
        q_place_comb(idx+1,qpsf,n , box);
    }
    //method 2: using vector accepted
    
    vector<int> row(20,0);
    vector<int> col(20,0);
    vector<int> diag(20,0);
    vector<int> adiag(20,0);

class Solution {
public:
    
    vector<vector<string>>sol;
    
    vector<vector<string>> solveNQueens(int n) {
        
        
        
        vector<string>box(n,string(n,'.'));  //got tle without this
        
         q_place_comb(0 , 0 ,n ,box);
        
        return sol;
    }
   
    bool canplace2(int r,int c,vector<string>&box)  //pass the box vector by reference
    { 
        if(row[r] == true || col[c] == true || diag[r-c+box.size()-1] == true || adiag[r+c] == true)
             return false;
        
        return true;
    }
   
    void q_place_comb(int idx , int qpsf , int n ,vector<string>& box)
    {
        if(idx == n*n || qpsf == n)
        {
            if(qpsf == n)
            {
                sol.push_back(box);
                
                return;
            }
            return;
        }
        
        int r = idx/n;
        
        int c = idx%n;
        
        if(canplace2(r,c,box))
        {
             row[r] = true;
            
             col[c] = true;
            
             diag[r-c+box.size()-1]= true;
            
             adiag[r+c] = true;
            
             box[r][c] ='Q';
            
             q_place_comb(idx+1 , qpsf+1 , n,box );
            
             row[r] = false;
             
             col[c] = false;
            
             diag[r-c+box.size()-1]= false;
            
            adiag[r+c] = false;
             
            box[r][c] ='.';
        } 
        
        q_place_comb(idx+1,qpsf,n , box);
    }
//==============method 3=========
class Solution {
public:
    
    vector<vector<string>>sol;
    
    vector<vector<string>> solveNQueens(int n) {
        
        
        
        vector<string>box(n,string(n,'.'));
        
         q_place_comb(0 , 0 ,n ,box);
        
        return sol;
    }
   
  /**  bool canplace2(int r,int c,vector<string>box)
    {
        if(row[r] == true || col[c] == true || diag[r-c+box.size()-1] == true || adiag[r+c] == true)
             return false;
        
        return true;
    }*/
   
    int row =0;
    int col = 0;
    int diag = 0;
    int anti = 0;
    
    bool canplace3(int r,int c,vector<string>&box)
    {
       if(!(row & (1<<r)) && !(col &(1<<c)) && !(diag & (1<<(r-c+box.size() -1))) && !(anti & (1<<(r+c))))
           return true;
        
        return false;
    }
    void q_place_comb(int idx , int qpsf , int n ,vector<string>& box)
    {
        if(idx == n*n || qpsf == n)
        {
            if(qpsf == n)
            {
                sol.push_back(box);
                
                return;
            }
            return;
        }
        
        int r = idx/n;
        
        int c = idx%n;
        
        if(canplace3(r,c,box))
        {
             row =(row ^ (1<<r));
            
             col = (col ^(1<<c));
            
             diag =(diag^(1<<(r-c+n-1)));
            
             anti = (anti^(1<<(r+c)));
            
            box[r][c] ='Q';
            
             q_place_comb(idx+1,qpsf+1,n,box);
            
            row =(row ^ (1<<r));
            
             col = (col ^(1<<c));
            
             diag =(diag^(1<<(r-c+n-1)));
            
             anti = (anti^(1<<(r+c)));
            
            box[r][c] ='.';
            
        } 
        
        q_place_comb(idx+1,qpsf,n , box);
    }
};
//nqueen ii leetcode return the number of solutions
    
  vector<int> row(20,0); //when they were declared inside the class it gave an error called expected the parameter declarator
    vector<int> col(20,0);
    vector<int> diag(20,0);
    vector<int> adiag(20,0);


class Solution {
public:
    
    int totalNQueens(int n) {
        
        vector<string>box(n,string(n,'.'));
        return q_place_comb(0,0,n,box);
        
    }
    
      bool canplace2(int r,int c,vector<string>&box)
    {
        if(row[r] == true || col[c] == true || diag[r-c+box.size()-1] == true || adiag[r+c] == true)
             return false;
        
        return true;
    }
   

    int q_place_comb(int idx , int qpsf , int n ,vector<string>& box)
    {
        if(idx == n*n || qpsf == n)
        {
            if(qpsf == n)
            {
                
                
                return 1;
            }
            return 0;
        }
        
        int r = idx/n;
        
        int c = idx%n;
        int count =0;
        if(canplace2(r,c,box))
        {
             row[r] = true;
            
             col[c] = true;
            
             diag[r-c+box.size()-1]= true;
            
             adiag[r+c] = true;
            
             box[r][c] ='Q';
            
             count+=q_place_comb(idx+1 , qpsf+1 , n,box );
            
             row[r] = false;
             
             col[c] = false;
            
             diag[r-c+box.size()-1]= false;
            
            adiag[r+c] = false;
             
            box[r][c] ='.';
        } 
        
        count+=q_place_comb(idx+1,qpsf,n , box);
        return count;
    }
};
