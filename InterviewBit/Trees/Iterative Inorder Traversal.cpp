/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> result;
    if(A==NULL)
    return result;
    
    stack<TreeNode*> s;
    while(true){
        if(A!=NULL){
            s.push(A);
            A = A->left;
        }
        else{
            if(s.empty())
            break;
            TreeNode* curr = s.top();
            result.push_back(curr->val);
            s.pop();
            A = curr->right;
        }
    }
    return result;
}

