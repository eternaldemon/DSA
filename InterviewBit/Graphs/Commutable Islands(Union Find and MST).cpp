bool comparator(vector<int> v1, vector<int> v2){
    return v1[2]<v2[2];
}

int find(vector<int>& parent, int index){
    if(parent[index]<0)
    return index;
    return find(parent, parent[index]);
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> parent(A+1,-1);
    sort(B.begin(),B.end(),comparator);
    int count = 0;
    int sum = 0;
    
    for(int i=0;i<B.size();i++){
        if(count == A-1)
        break;
        
        int x = find(parent,B[i][0]);
        int y = find(parent,B[i][1]);
        if(x!=y){
            sum = sum + B[i][2];
            count++;
            parent[x] = y;
        }
    }
    return sum;
}

