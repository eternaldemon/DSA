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
 
#LEETCODE QUESTION 1339
class Solution {
public:
    int helper(TreeNode* root,vector<unsigned long long>&m){
        int left=0,right=0;
        if(root->left)
            left = helper(root->left,m);
        if(root->right)
            right = helper(root->right,m);
        
        m.push_back(root->val + left+ right);
        return root->val+left+right;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->val;
        vector<unsigned long long> m;
        unsigned long long sum = helper(root,m);
        unsigned long long diff=0,temp=0;
        for(int i=m.size()-1;i>=0;i--){
            temp = (sum-m[i])*m[i];
            diff = max(diff,temp);
        }
        return diff % ((unsigned long int)pow(10,9) + 7);
    }
};
