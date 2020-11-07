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
TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int start,int end,int&index){
    if(start>end)
    return NULL;
    //static int index = 0;
    TreeNode* root = new TreeNode(postorder[index]);
    index--;
    if(start==end)
    return root;
    
    int temp = search(inorder,start,end,root->val);
    root->right = solve(inorder, postorder, temp+1,end,index);
    root->left = solve(inorder, postorder,start,temp-1,index);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int index = postorder.size()-1;
    TreeNode* root= solve(inorder,postorder,0,inorder.size()-1,index);
    return root;
}

