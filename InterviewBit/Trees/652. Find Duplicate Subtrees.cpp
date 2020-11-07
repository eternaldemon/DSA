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
#LEETCODEEEEEE
class Solution {
public:
    string inorder(TreeNode* root, vector<TreeNode*>&result, unordered_map<string,int>&m){
        if(!root)
            return "";
        
        string str = "(";
        str += inorder(root->left,result,m);
        str += to_string(root->val);
        str += inorder(root->right,result,m);
        str += ")";
        
        if(m[str] == 1)
            result.push_back(root);
        
        
        m[str]++;
        
        
        return str;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode*> result;
        inorder(root,result,m);
        return result;
        
    }
};
