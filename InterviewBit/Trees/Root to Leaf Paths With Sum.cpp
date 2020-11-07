/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, int target,vector<vector<int>>& result,vector<int>&temp){
    if(root==NULL)
    return;
    temp.push_back(root->val);
    if(root->val==target && root->left==NULL && root->right==NULL)
    result.push_back(temp);
    solve(root->left,target-root->val,result,temp);
    solve(root->right,target-root->val,result,temp);
    
    temp.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> result;
    vector<int> temp;
    solve(A,B,result,temp);
    return result;
}

