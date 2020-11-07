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
    else if(root->left==NULL)
    return 1+height(root->right);
    else if(root->right==NULL)
    return 1+height(root->left);
    return 1+min(height(root->left),height(root->right));
}
int Solution::minDepth(TreeNode* A) {
    int result = height(A);
    return result;
}

