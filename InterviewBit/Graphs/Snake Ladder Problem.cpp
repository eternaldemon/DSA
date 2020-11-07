int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int,int> adj;
    vector<int> visited(101,-1);
    for(int i=0;i<A.size();i++){
        adj[A[i][0]] = A[i][1];
    }
    for(int i=0;i<B.size();i++){
        adj[B[i][0]] = B[i][1];
    }
    queue<int> q;
    q.push(1);
    visited[1] =0;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr==100)
        return visited[curr];
        for(int i=1;i<=6;i++){
            int child = curr+i;
            if(child>100)
            continue;
            if(adj.find(child)!=adj.end())
            child = adj[child];
            if(visited[child]==-1){
                visited[child] = visited[curr]+1;
                q.push(child);
            }
        }
    }
    return -1;
}

