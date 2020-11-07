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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        int result = check(root,sum);
        int leftval = pathSum(root->left,sum);
        int rightval = pathSum(root->right,sum);
        return result + leftval + rightval;
    }
    
    int check(TreeNode* root, int target){
        if(root==NULL)
            return 0;
        int count = 0;
        if(root->val == target)
            count++;
        if(root->left!=NULL)
        count = count + check(root->left,target-root->val);
        if(root->right!=NULL)
        count = count + check(root->right,target-root->val);
        
        return count;
    }
};
