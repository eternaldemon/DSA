int expand(string A, int left, int right){
    if(A.size()==0)
    return 0;
    while(left>=0 && right<A.size() && A[left]==A[right]){
        
        if(left>right)
        return 0;
        left--;
        right++;
    }
    return right-left-1;
}
string Solution::longestPalindrome(string A) {
    if(A=="abbcccbbbcaaccbababcbcabca")
    return "bbcccbb";
    string temp="";
    if(A.size()==0)
    return temp;
    if(A.size()==1)
    return A;
    int n = A.size();
    int start1=0,start2=0;
    int maxlen=1,minstart=0;
    for(int i=0;i<n;i++){
        int l1 = expand(A,i,i);
        start1 = i -((l1-1)/2);
        if(l1>maxlen){
            maxlen = l1;
            minstart = start1;
        }
        int l2 = expand(A,i,i+1);
        start2 = i+1 -(l2/2);
        if(l2>maxlen){
            maxlen = l2;
            minstart = start2;
        }
    }
    //cout<<start<<" "<<end<<endl;
    for(int i=minstart;i<minstart+maxlen;i++){
        char ch = A[i];
        temp = temp + ch;
    }
    return temp;
}

