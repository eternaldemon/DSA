/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode* A, TreeNode* B){
    if(A==NULL && B==NULL)
    return true;
    else if (A==NULL || B==NULL)
    return false;
    if(A->val!=B->val)
    return false;
    return solve(A->left,B->right)&&solve(A->right,B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(A!=NULL && A->left==NULL && A->right==NULL)
    return true;
    if(A==NULL)
    return true;
    bool result = solve(A->left,A->right);
    return result;
}

