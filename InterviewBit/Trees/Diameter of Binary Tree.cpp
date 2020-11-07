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
    int height(TreeNode* root,int& ans){
        if(root==NULL)
            return 0;
        int lh,rh;
        lh = height(root->left,ans);
        rh = height(root->right,ans);
        ans = max(ans, (lh+rh));//diameter is stored in ans not in result;//Sometimes it will be 1+lh+rh
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        if(root==NULL)
            return 0;
        int result = height(root,ans);//result has height but ans has diameter. Check the height function.
        return ans;
    }
};
