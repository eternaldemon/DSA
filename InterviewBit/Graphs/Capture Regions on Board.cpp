void dfs(int i, int j, vector<vector<char>>& A){
    if(i>=0 && i<A.size() && j>=0 && j<A[0].size() && A[i][j]=='O'){
        A[i][j] = '*';
        dfs(i+1,j,A);
        dfs(i-1,j,A);
        dfs(i,j+1,A);
        dfs(i,j-1,A);
    }
}
void Solution::solve(vector<vector<char> > &A) {
    int m = A.size();
    int n = A[0].size();
    for(int i=0;i<m;i++){
        if(A[i][0]=='O')
        dfs(i,0,A);
        if(A[i][n-1]=='O')
        dfs(i,n-1,A);
    }
    for(int i=0;i<n;i++){
        if(A[0][i]=='O')
        dfs(0,i,A);
        if(A[m-1][i]=='O')
        dfs(m-1,i,A);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]=='O')
            A[i][j]= 'X';
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]=='*')
            A[i][j]= 'O';
        }
    }
}

