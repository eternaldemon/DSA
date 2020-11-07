int Solution::anytwo(string A) {
    if(A.size()==1)
    return 0;
    
    vector<vector<int>> dp(A.size()+1,vector<int>(A.size()+1,0));
    for(int i=0;i<A.size()+1;i++)
    dp[i][0]= 0 ;
    
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<A.size()+1;j++){
            if(A[i-1]==A[j-1] && i!=j)
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    if(dp[A.size()][A.size()]>=2)
    return 1;
    
    return 0;
}

