//Cycle in Unidrected Graph using parent method
bool check(int u, vector<vector<int>> adj, vector<bool>& visited, vector<int>&parent){
    visited[u] = true;
    
    for(auto i:adj[u]){
        if(!visited[i]){
            parent[i] = u;
            if(check(i,adj,visited,parent))
            return true;
        }
        else if(parent[u]!=i)
        return true;
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
    vector<bool> visited(A+1,false);
    vector<int> parent(A+1,-1);
    
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    for(int i=1 ;i<A+1;i++){
        if(visited[i]==0){
            if(check(i,adj,visited,parent)){
                return true;
            }    
        }
            
    }
    return false;
}

