/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* root){
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    int lh = 1 + height(root->left);
    int rh = 1 + height(root->right);
    if(lh<0||rh<0)
    return INT_MIN;
    if(abs(lh-rh)>1)
    return INT_MIN;
    return max(lh,rh);
}
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL)
    return 1;
    //int lh = height(A->left);
    //int rh = height(A->right);
    int t = height(A);
    //int result = abs(lh-rh);
    if(t<0)
    return 0;
    return 1;
}

