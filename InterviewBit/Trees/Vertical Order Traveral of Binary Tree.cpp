/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(A==NULL)
    return vector<vector<int>>();
    vector<vector<int>> result;
    map<int,vector<int>> m;
    queue<pair<TreeNode*,int>> q;
    int level = 0;
    q.push(make_pair(A,level));
    
    while(!q.empty()){
        TreeNode* curr = q.front().first;
        int level = q.front().second;
        q.pop();
        m[level].push_back(curr->val);
        
        if(curr->left!=NULL)
        q.push(make_pair(curr->left,level-1));
        if(curr->right!=NULL)
        q.push(make_pair(curr->right,level+1));
    }
    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        result.push_back(it->second);
    }
    return result;
}

