//Can be done by using Longest Increasing Subsequence from start and back and adding max of both 
int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size()==0)
    return 0;
    if(A.size()==1)
    return 1;
    int n = A.size();
    vector<int>dp(n,1);
    vector<int>temp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j] && dp[i]<dp[j]+1)
            dp[i] = dp[j] + 1;
            if(A[i]<A[j] && temp[i]<temp[j]+1)
            temp[i] = temp[j]+1;
            if(A[i]<A[j] && temp[i]<dp[j]+1)
            temp[i] = dp[j] + 1;
        }
    }
    int result = max(*max_element(dp.begin(),dp.end()),*max_element(temp.begin(),temp.end()));
    return result;
}

