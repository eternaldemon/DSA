vector<int> Solution::prevSmaller(vector<int> &A) {
    if(A.size()==1){
        vector<int> temp(1,-1);
        return temp;
    }
    stack<int> s;
    vector<int> result;
    for(int i=0;i<A.size();i++){
        while(!s.empty() && A[s.top()]>=A[i]){
            s.pop();
        }
        if(s.empty()){
            result.push_back(-1);
        }
        else{
            result.push_back(A[s.top()]);
        }
        s.push(i);
    }
    return result;
}

