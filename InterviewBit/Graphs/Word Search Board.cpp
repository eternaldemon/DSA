bool dfs(int i, int j, vector<string>& A, string B, int idx){
    if(idx == B.size())
    return true;
    if(i<0||i>=A.size()||j<0||j>=A[0].size()||A[i][j]!=B[idx])
    return false;
    idx++;
    return dfs(i+1,j,A,B,idx)||dfs(i-1,j,A,B,idx)||dfs(i,j+1,A,B,idx)||dfs(i,j-1,A,B,idx);
}
int Solution::exist(vector<string> &A, string B) {
    if(A.empty())
    return 0;
    if(B.empty())
    return 1;
    int m = A.size();
    int n = A[0].size();
    int result = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]== B[0])
                if(dfs(i,j,A,B,0))
                return 1;
        }
    }
    return 0;
}

