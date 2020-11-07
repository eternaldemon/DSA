int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int result = INT_MIN;
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            dp[i][j] = A[i][j];
            dp[i][j] = dp[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
            result = max(result,dp[i][j]);
        }
    }
    return result;
}

