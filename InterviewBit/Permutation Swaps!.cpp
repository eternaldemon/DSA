int find(vector<int>&parent, int index){
    if(parent[index]<0)
    return index;
    return find(parent, parent[index]);
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    int m = B.size();
    if(m!=n)
    return 0;
    if(m==0 && n==0)
    return 1;
    if(A==B)
    return 1;
    vector<int> parent(n+1,-1);
    
    for(int i=0;i<C.size();i++){
        int x = A[C[i][0]-1];
        int y = A[C[i][1]-1];
        int find1 = find(parent,x);
        int find2 = find(parent,y);
        if(find1!=find2){
            parent[find2] = find1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(A[i]!=B[i]){
            int x = find(parent,A[i]);
            int y = find(parent,B[i]);
            if(x!=y)
            return 0;
        }
    }
    return 1;
}

