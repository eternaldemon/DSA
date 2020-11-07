int Solution::solve(string A) {
    string inputr = reverse(A.begin(),A.end());
    int m = A.size();
    vector<vector<int>> dp(m+1,vector<int>(m+1,0));
    for(int i=0;i<m+1;i++){
        dp[i][0]=0;
    }
    
    for(int i=1;i<m+1;i++){
        for(int j=1;j<m+1;j++){
            if(A[i-1]==inputr[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][m];
}

