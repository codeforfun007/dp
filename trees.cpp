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
// ========gfg :  check if subtree ======
bool sametree(Node* a,Node* b)
{
    if(a == NULL && b== NULL)
      return true;
    
    if(a == NULL || b== NULL)
      return false;
    
    return a->data == b->data &&sametree(a->left,b->left) && sametree(a->right,b->right);
}
/*you are required to
complete this function */
bool isSubTree(Node* T, Node* S) {
    // Your code here
    // return 1 if S is subtree of T else 0
     if(S == NULL)return true;
    
    if(T == NULL)return false;
    
    return sametree(T,S)||isSubTree(T->left,S)||isSubTree(T->right,S);
}
