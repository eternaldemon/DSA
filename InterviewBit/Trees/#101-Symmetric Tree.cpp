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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        //Return a helper function for the root node.
        return ismirror(root->left,root->right);
    }
    
    bool ismirror(TreeNode* node1,TreeNode* node2){
    	//Checks if both are null or if only one is null and returns accordingly
        if(node1==NULL && node2==NULL)
            return true;
        else if(node1==NULL || node2==NULL)
            return false;
        //if not equal then return false
        if(node1->val!=node2->val){
            return false;
        }
        //If equal then check for the left and right subtree of each node.
        return ismirror(node1->left,node2->right) && ismirror(node1->right,node2->left);
    }

};
