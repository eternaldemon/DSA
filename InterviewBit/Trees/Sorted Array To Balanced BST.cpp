/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* insertnode(const vector<int>&A, int start, int end){
    if(start>end)
    return nullptr;
    
    int mid = (start+end)/2 ;
    TreeNode* root = new TreeNode(A[mid]);
        root->left = insertnode(A,start,mid-1);
        root->right = insertnode(A,mid+1,end);
        
    return root;
    
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(A.size()==0)
    return nullptr;
    TreeNode* root = insertnode(A,0,A.size()-1);
    return root;    
}

