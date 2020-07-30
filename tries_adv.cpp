//shortest unique prefix of all the words provided in the dictionary

#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
    int wordend = 0;
    vector<node*>child;
    int f = 0;

    node()
    {
        this->child.assign(26,NULL);
        f = 0;
        wordend = 0;
    }
};
node* root = NULL;
void insert(string &word)
{
    node* cur = root;
    
    int n = word.size();
    int i=0;
    while(i<n)
    {
        int idx = word[i]-'a';
        if(cur->child[idx] == NULL)cur->child[idx] = new node();
        cur->child[idx]->f++;
        cur = cur->child[idx];
        i++;
    }
    cur->wordend++;
}
string  shortest_unique_pre(string &word)
{
    int n = word.size();
    node* cur = root;
    int i=0;
    
   string ans = "";

    while(i<n)
    {
         int idx = word[i]-'a';
         ans = ans+word[i];
         if(cur->child[idx] == NULL)return "";
         cur = cur->child[idx];
         if(cur->f==1)return ans;
         i++;
    }
    return "";
}

//output:
/*No unique prefix
dog
dov
dul
No unique prefix
cobras
z
duc*/

void solve()
{
    vector<string>dict = {"cobra","dog","dove","dull","cobra","cobras","zebra","duck"};
     root = new node();
    for(string x: dict)
    {
        insert(x);
    }

    for(string x: dict)
    {
        string ans = shortest_unique_pre(x);
        if(ans.size() == 0)
           cout<<"No unique prefix\n";
        else
        cout<<ans<<endl;
    }
}
int main(){

   solve();

	return 0;
}

//leetcode 421: max xor pair of two numbers in array


class node
{
    public:
    vector<node*>child;
    int wordend;
    
    node()
    {
        this->child.assign(2,NULL);
        wordend=0 ;
    }
};

node* root = NULL;

void insert(int& num)
{
    node* cur = root;
    
    for(int i=31;i>=0 ;i--)
    {
        int idx = (num>>i)&1;
        if(cur->child[idx] == NULL)cur->child[idx] = new node();
        
        cur = cur->child[idx];
    }
    cur->wordend++;
}

int max_xor(int& num)
{
    node* cur = root;
    
    int ans =0;
    for(int i=31 ;i>=0 ;i--)
    {
        int idx = (num>>i)&1;
        
        int comp = (!idx);
        if(cur->child[comp] != NULL)
        {
            ans += (1<<i);  //2^i
            cur = cur->child[comp];
        }
         else if(cur->child[idx]!= NULL)
        {
             //ans += 0*..
            cur = cur->child[idx];
        }
        else
            return ans;
    }
    return ans;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        root = new node();
        
        for(int x : nums)
         insert(x);
    
        int res =0;
        for(int x : nums)
            res = max(res , max_xor(x));
        
        return res;
    }
};

//maximum xor of subarray of an array problem
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    vector<node*>child;
    node()
    {
        this->child.assign(2,NULL);
    }
};
node* root = NULL;
void insert(int &num)
{
    node* cur = root;
    
    for(int i=31;i>=0 ;i--)
    {
        int idx = (num>>i)&1;
       
       if(cur->child[idx] == NULL)cur->child[idx] =new node();

       cur = cur->child[idx];
    }
}

int max_xor(int &num)
{
    node* cur = root;
    int ans =0;
    for(int i=31;i>=0 ;i--)
    {
        int idx = (num>>i)&1;
        int comp = (!idx);

        if(cur->child[comp] != NULL)
        {
           ans += (1<<i);
           cur = cur->child[comp];
        }
        else if(cur->child[idx] != NULL)
        {
            cur = cur->child[idx];
        }
        else
          return ans;
    }
    return ans;
}

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
    root = new node();  //node* root = new node() gave segmentation error because root is a global variable
                        //and we tried to declare it here again
    int n;
    cin>>n;

    vector<int>v(n);
    vector<int>comm(n);
    for(int i=0;i<n;i++)
      cin>>v[i];
    comm[0] = v[0];

    for(int i=1;i<n;i++)
      comm[i] =(v[i]^comm[i-1]);
    
    for(int x :comm)
      insert(x);
    
    int res = 0;

    for(int x : comm)
     res = max(res,max_xor(x));

    cout<<res<<endl;
     root = NULL;
    }

}
int main(){

   solve();

	return 0;
}
