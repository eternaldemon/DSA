/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int search(vector<int>& inorder,int start, int end, int value){
    for(int i=start;i<=end;i++){
        if(inorder[i]==value){
            return i;
        }
    }
} 
TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int&index){
    if(start>end)
    return NULL;
    //static int index = 0;
    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    if(start==end)
    return root;
    
    int temp = search(inorder,start,end,root->val);
    root->left = solve(preorder, inorder,start,temp-1,index);
    root->right = solve(preorder, inorder, temp+1,end,index);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int index = 0;
    TreeNode* root= solve(preorder,inorder,0,inorder.size()-1,index);
    return root;
}

