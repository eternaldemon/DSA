/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        
        return result;
    }
    
    void inorder(TreeNode* head){
        if(head==NULL)
            return;
        inorder(head->left);
        //cout<<head->val<<endl;
        result.push_back(head->val);
        inorder(head->right);
        
    }
};
