#define MOD 1000000007
int Solution::hammingDistance(const vector<int> &A) {
    if(A.size()==1)
    return 0;
    long long int result=0;
    for(int i=0;i<31;i++){
        long long int count = 0;
        for(int j=0;j<A.size();j++){
            if((A[j] & 1<<i))
            count++;
        }
        result += (count*(A.size()-count)*2);
        result = result%MOD;
    }
    return result;
}

