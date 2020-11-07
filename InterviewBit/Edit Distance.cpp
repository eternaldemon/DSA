int Solution::minDistance(string A, string B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    for(int i=0;i<m+1;i++){
    dp[i][0] = i;
    }
    
    for(int i=0;i<n+1;i++){
    dp[0][i] = i;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(A[i-1]==B[j-1])
            dp[i][j] = dp[i-1][j-1];
            else
            dp[i][j] = 1 +min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

