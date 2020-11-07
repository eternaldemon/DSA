vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<int,vector<int>,greater<int>> pq;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            int sum = A[i] + B[j];
            if(i==0)
            pq.push(sum);
            else if(sum>pq.top()){
                pq.pop();
                pq.push(sum);
            }
            else 
            break;
        }
    }
    int i = pq.size()-1;
    vector<int> result(pq.size(),0);
    while(!pq.empty()){
        result[i] = pq.top();
        i--;
        pq.pop();
    }
    return result;
}

