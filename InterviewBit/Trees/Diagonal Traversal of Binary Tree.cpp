/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    if(A==NULL)
    return vector<int>();
    queue<TreeNode*> q;
    TreeNode* root = A;
    vector<int> result;
    while(root!=NULL){
        q.push(root);
        root = root->right;
    }
    TreeNode* dummy = new TreeNode(-1);
    q.push(dummy);
    while(q.size()!=1){
        TreeNode* curr = q.front();
        q.pop();
        if(curr!=dummy){
            result.push_back(curr->val);
            TreeNode* temp = curr->left;
            while(temp!=NULL){
                q.push(temp);
                temp = temp->right;
            }
        }
        else{
                q.push(dummy);
            }
        }
    
    return result;
}

