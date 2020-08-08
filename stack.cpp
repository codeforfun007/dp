//spoj : street parade

#include <bits/stdc++.h>
using namespace std;
int main() {

  while(-1)
  {
  int n;
  cin>>n;
  
  if(n == 0)
   break;
  vector<int>v(n);
  for(int i=0;i<n ;i++)
  {
       cin>>v[i];
  }
   
   stack<int>s;

   stack<int>ans;

  for(int x : v)
  {
      while(!s.empty() && s.top() < x)  //remember this one . use && instead of ||
    {
        ans.push(s.top());
        s.pop();
    }
    s.push(x);
  }

  while(!s.empty())
  {
      ans.push(s.top());
      s.pop();
  }
  bool yes = true;

  for(int i =n ;i>=1;i--)
  {
      if( ans.top() != i)
      {
          cout<<"no\n";
          yes = false;
          break;
      }
      ans.pop();
  }
  if(yes == true)
  cout<<"yes\n" ;

  }
  return 0;
}
