int Solution::maxSubArray(const vector<int> &A) {
    if(A.size()==1)
    return A[0];
    
    int sum_curr= 0, maxtillnow = INT_MIN;
    
    for(int i=0;i<A.size();i++){
        sum_curr = sum_curr + A[i];
        maxtillnow = max(sum_curr,maxtillnow);
        if(sum_curr<0)
        sum_curr = 0;
        
    }
    return maxtillnow;
}

