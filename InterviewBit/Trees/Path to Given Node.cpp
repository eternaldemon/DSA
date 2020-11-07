/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool path(TreeNode* root, int B, vector<int>& result){
    if(root==NULL)
    return 0;
    if(root->val==B){
    result.push_back(root->val);
    return 1;
    }
    int ans1 = path(root->left,B,result);
    int ans2 = path(root->right,B,result);
    if(ans1){
        result.push_back(root->left->val);
    }
    if(ans2){
        result.push_back(root->right->val);
    }
    return ans1||ans2;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> result;
    bool ans = path(A,B,result);
    result.push_back(A->val);
    reverse(result.begin(),result.end());
    result.pop_back();
    return result;
}

