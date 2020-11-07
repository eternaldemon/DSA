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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || val==root->val)
            return root;
        while(true){
            if(root==NULL)
                break;
            if(root->val==val)
                break;
            if(val>root->val){
                root = root->right;            
            }
            else if(val<root->val){
                root = root ->left;
            }
        }
        return root;
    }
};
