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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode *> q;
        if(root==NULL)
            return result;
        q.push(root);
        while(!q.empty()){
            double size=q.size(),sum=0;
            for(double i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                sum = sum + curr->val;
                //cout<<sum<<" ";
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }
};
