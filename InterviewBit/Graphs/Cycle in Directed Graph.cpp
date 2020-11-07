//Cycle in Directed Graph using colors
//{0->not processed,1->processing, 2->processed}
// While dfs is being done for node and any node in its list has color= 1 this means a deadlock and hence a loop.
//While dfs is being done for a node and if its neighbour node has color=0 then we do a dfs on it too.(line 12).
bool Cyclic(int u, vector<vector<int>>& adj, vector<int>& colors){
    
    colors[u] = 1;
    
    for(auto i:adj[u]){
        if(colors[i]==1)
            return true;
        if(colors[i]==0 && Cyclic(i,adj,colors))//Unprocessed but has back edge
            return true;
    }
    colors[u] = 2;
    //cout<<"RETURNING FALSE";
    return false;
}


int Solution::solve(int A, vector<vector<int>> &B) {
    vector<int> colors(A+1,0);//{0->not processed,1->processing, 2->processed}
    vector<vector<int>> adj(A+1);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
    }

    for(int i=1;i<=A;i++)
        if(colors[i]==0)
            if(Cyclic(i,adj,colors)==true)
                return true;
            
    
    return false;
}
