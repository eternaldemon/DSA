/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int pathsum(TreeNode* root, int&result){
    if(root==NULL)
    return NULL;
    int ansl = pathsum(root->left,result);
    int ansr = pathsum(root->right,result);
    int temp = max(ansl,ansr);
    int max1 = max(temp+root->val,root->val);
    int max2 = max(max1, root->val+ansl+ansr);
    result  = max(result,max2);
    return max1;
}
int Solution::maxPathSum(TreeNode* A) {
    if(A==NULL)
    return NULL;
    if(A!=NULL && A->left==NULL && A->right==NULL)
    return A->val;
    int result = INT_MIN;
    int ans = pathsum(A,result);
    return result;
}
