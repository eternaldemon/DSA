void dfs(int i,int j,vector<string>&A,int &count,vector<vector<bool>>&visited){
    if(i>=0&& i<A.size()&&j>=0&&j<A[0].size()&&A[i][j]=='X'&&!visited[i][j]){
        visited[i][j] = true;
        dfs(i+1,j,A,count,visited);
        dfs(i-1,j,A,count,visited);
        dfs(i,j+1,A,count,visited);
        dfs(i,j-1,A,count,visited);
    }
}
int Solution::black(vector<string> &A) {
    int m =A.size();
    int n =A[0].size();
    int count = 0;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]=='X'){
                if(!visited[i][j]){
                    dfs(i,j,A,count,visited);
                    count++;
                }
            }
        }
    }
    return count;
}

