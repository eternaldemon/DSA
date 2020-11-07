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
 
 //Remeber that inorder traversal gives a sorted array if the tree is BST. Use this to your advantage
class Solution {
public:
    vector<int> values;
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        inorder(root);
        bool flag=true;
        for(int i=0;i<values.size()-1;i++){
            if(values[i]<values[i+1]){}
            else{
                flag=false;
            }
        }
        return flag;
    }
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }
};
