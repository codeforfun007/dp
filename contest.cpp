

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
       
       string s;
        cin>>s;

	vector<int>v(n , 0) ;
    
    vector<vector<int>>adj ;
    for(int i = 0;i<n ;i++)
    {
        if(s[i] == 'L' && i != 0)
        {
            v[i-1]++;
        }
        if(s[i] == 'R' && i!= n-1)
        {
            v[i+1]++;
        }
    }
     
     int count  = 0;
    for(int i = 0;i<n ;i++)
    {
        if(v[i] % 2 == 0)
         continue;
        
        if( i != 0 && s[i-1] == 'R' && s[i] == 'L')
        continue;

        if(i != n-1 && s[i] == 'R' && s[i+1] == 'L')
         continue;
        
        count++;
        if(i!= n-1 && s[i] == 'R')
         v[i+1]--;
        else if(i!= 0)
        v[i-1]--;
        
        if(s[i] == 'L')
        s[i] = 'R';
        else if(s[i] == 'R')
        s[i] = 'L';
    }
    cout<<count<<endl;
    }
    
	return 0;
}
