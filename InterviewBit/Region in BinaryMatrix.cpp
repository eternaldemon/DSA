void dfs(vector<vector<int>>& A, int i, int j, int& result){
    if(i>=0 && i<A.size() && j>=0 && j<A[0].size() && A[i][j]==1){
        result++;
        A[i][j] = 0;
        dfs(A,i+1,j,result);
        dfs(A,i-1,j,result);
        dfs(A,i,j+1,result);
        dfs(A,i,j-1,result);
        dfs(A,i+1,j+1,result);
        dfs(A,i+1,j-1,result);
        dfs(A,i-1,j+1,result);
        dfs(A,i-1,j-1,result);
    }
    return;
}
int Solution::solve(vector<vector<int> > &A) {
    int result = 0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==1){
                int count = 0;
                dfs(A,i,j,count);
                result= max(result,count);
            }
        }
    }
    return result;
}

