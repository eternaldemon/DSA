class Solution {
public:
    bool find(string A, string B){
    if(A.size()!=B.size())
    return false;
    int count = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i])
        count++;
    }
    return count==1;
}
    int ladderLength(string A, string B, vector<string>& C) {
    if(A.size()!=B.size())
    return 0;
    if(A!=B && C.size()==0)
    return 0;
    if(A==B)
    return 0;
    
    vector<bool> visited(C.size(),false);
    queue<pair<string,int>> q;
    q.push(make_pair(A,1));
    int level = 1;
    while(!q.empty()){
        string curr = q.front().first;
        level = q.front().second;
        q.pop();
        if(curr==B){
            return level;
        }
        
        for(int i=0;i<C.size();i++){
            if(visited[i]==false && find(C[i],curr)){
                visited[i] = true;
                q.push(make_pair(C[i],level+1));
                //cout<<C[i]<<"  "<<level+1<<endl;
            }
        }
    }
    return 0;
    }
};
