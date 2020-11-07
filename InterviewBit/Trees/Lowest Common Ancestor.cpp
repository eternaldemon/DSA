/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode* A,int target,vector<int>&temp){
    if(A==NULL)
    return false;
    temp.push_back(A->val);
    if(A->val==target)
    return true;
    if(solve(A->left,target,temp) || solve(A->right,target,temp))
    return true;
    temp.pop_back();
    return false;
}
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> temp1;
    vector<int> temp2;
    bool r1 = solve(A,B,temp1);
    bool r2 = solve(A,C,temp2);
    if(temp1.size()==0||temp2.size()==0)
        return -1;
    if(r1==false || r2==false)
        return -1;
    if(B==C)
    return B;
    int result=-1;
    /*
    for(int i=0;i<temp1.size();i++)
    cout<<temp1[i]<<" ";
    cout<<endl;
    for(int i=0;i<temp2.size();i++)
    cout<<temp2[i]<<" ";
    cout<<endl;
    */
    for(int i=0;i<temp1.size() && i<temp2.size();i++){
        if(temp1[i]==temp2[i]){
            result = temp1[i];
            }
        else
            break;
        }
    return result;
    //cout<<"RESULT:"<<result<<endl;
    //return temp1[result-1]; 
}

