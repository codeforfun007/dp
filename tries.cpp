//======leetcode 208 : impliment tries===========================
class node
{
    public :
    vector<node*>child;
    int wordend = 0;
    
    node()
    {
        this->child.assign(26,NULL);
        wordend = 0;
    }
};

class Trie {
public:
    node* root = NULL;
    /** Initialize your data structure here. */
    Trie() {
        
        root  = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        node* cur = root;
        int n = word.size();
        
        for(int i=0;i<n ;i++)
        {
            int idx = word[i]-'a';
            
            if(cur->child[idx] == NULL)
            {
                cur->child[idx] = new node();
                
            }
            cur = cur->child[idx];
        }
        cur->wordend++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {

        node* cur = root;
        int n = word.size();
        
        for(int i=0;i<n;i++)
        {
            int idx =  word[i]-'a';
            
            cur = cur->child[idx];
            if(cur == NULL)return false;
        }
        return cur->wordend>0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         node* cur = root;
        int n = prefix.size();
        
        for(int i=0;i<n;i++)
        {
            int idx =  prefix[i]-'a';
            
            cur = cur->child[idx];
            if(cur == NULL)return false;
        }
        return true;
    }
};

//== leetcode 211 : add and search word====================================
 class node{
    public:
    int wordend = 0;
    vector<node*>child;
    
    node()
    {
        wordend = 0;
        this->child.assign(26,NULL);
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    node* root = NULL;
    WordDictionary() {
        
        root = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node* cur = root;
        int n = word.size();
        
        for(int i=0;i<n ;i++)
        {
            int idx = word[i] - 'a';
            
            if(cur->child[idx] == NULL)
            {
                cur->child[idx] = new node();
            }
            cur = cur->child[idx];
        }
        cur->wordend++;
    }
    bool search_(node* cur , int idx ,string &word)
    {
         if(cur == NULL)
            return false;
        
        if(idx == word.size())
            return cur->wordend>0;
        
       
        
        bool res = false;
        if(word[idx] == '.')
        {
            for(int i=0;i<26;i++)
            {
                if(cur->child[i] != NULL)
                    res = res||search_(cur->child[i],idx+1,word);
            }
        }
        else
        {
            int i = word[idx] - 'a';
            
            res = search_(cur->child[i] ,idx+1 , word);
        }
        return res;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      node* cur = root;
       return search_(cur , 0 , word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
//==============leetcode 212 : worde seach ii =================


class Solution {
public:
    class node
{
    public:
    int wordend =0;
    vector<node*>child;
    string word = "";
        
    node()
    {
        wordend = 0;
        child.assign(26,NULL);
        this->word ="";
    }
};
node * root = NULL;
void add(string word)
{
    int n = word.size();
    node* cur = root;
    
    for(int i=0;i<n;i++)
    {
        int idx = word[i]-'a';
        
        if(cur->child[idx] == NULL)
            cur->child[idx] = new node();
        
        cur = cur->child[idx];
    }
    cur->wordend++;
    cur->word = word;
}
vector<string>ans;

vector<vector<int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int r ,int c ,node * cur,vector<vector<char>>& board)
{
   if(cur->wordend>0)
   {
       ans.push_back(cur->word);
       cur->wordend = 0;
   }
    char ch = board[r][c];
    board[r][c] ='$';
    
    for(int d = 0;d<dir.size();d++)
    {
        int x = r + dir[d][0];
        int y = c + dir[d][1];
        
        if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y] != '$' && cur->child[board[x][y]-'a']!= NULL)
            dfs(x , y,cur->child[board[x][y]-'a'],board);
    }
    
    board[r][c] = ch;
}



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        root = new node();
        
        for(string x:words)
        {
            add(x);
        }
        
        int n = board.size();
        int m = board[0].size();
        node* cur = root;
        for(int i=0;i<n ;i++)
        {
            for(int j=0;j<m ;j++)
            {
                int idx = board[i][j] - 'a';
                
                if(cur->child[idx]!= NULL)
                {
                    
                    dfs(i , j,cur->child[idx],board );
                }
            }
        }
        
        return ans;
    }
};
//======leetcode 79 : word search =========================
//======we just have to search one word from board ==========

//so we don't need to make tries and keep the list of word. 
// a simple dfs with a little backtracking to ensure that not to 
//visit already visited word will be sufficient.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        bool res = false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                 res = res||   dfs(i , j , 1 , word , board);
            }
        }
        return res;
    }
    vector<vector<int>>dir = {{-1,0},{0,-1} ,{1,0},{0,1}};
    bool dfs(int r ,int c , int idx , string &word ,vector<vector<char>>& board )
    {
        if(idx == word.size())
            return true;
        
        char ch2 = board[r][c];
        board[r][c] = '$';
        char ch = word[idx];
        bool res = false;
        for(int d = 0;d<dir.size();d++)
        {
            int x = dir[d][0] + r;
            int y = dir[d][1] + c;
            
            if(x >=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]== ch )
               res= res|| dfs( x ,y ,idx+1 , word,board);
        }
        
        board[r][c] = ch2;
        return res;
    }
};
