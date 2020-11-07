int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0)
    return 0;
    int mx = INT_MIN, mn = INT_MAX;
    
    for(int i=0;i<A.size();i++){
        mn = min(mn,A[i]);
        mx = max(A[i]-mn, mx);
    }
    return mx;
}

