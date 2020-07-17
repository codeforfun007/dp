//sum tree : gfg

// Should return true if tree is Sum Tree, else false

pair<bool,int> solve(Node* root)
{
    if(root == NULL)return {true,0};
    
    if(root->left == NULL && root->right == NULL)
      return {true,root->data};

    pair<bool,int>left = solve(root->left);
    
    pair<bool,int>right = solve(root->right);
    
    int sum = left.second + right.second;
    
    bool ans = left.first && right.first && root->data == sum;
    
    return {ans,sum+root->data};
}
bool isSumTree(Node* root)
{
     // Your code here
     
   return solve(root).first;
}
