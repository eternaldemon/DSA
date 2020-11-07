/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool pathsum(TreeNode* root,int target){
    if(root==NULL)
    return false;
    if(root->val==target && root->left==NULL && root->right==NULL)
    return true;
    if(pathsum(root->left,target-root->val) || pathsum(root->right,target-root->val))
    return true;

    return false;
}
int Solution::hasPathSum(TreeNode* A, int B) {
    return pathsum(A,B);
}

