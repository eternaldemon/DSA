class Solution {
public:
    //0-unvisited,1-processed,2-processing
    bool isCyclic(int current, vector<vector<int>>&list, vector<int>& vis){
        // If vis[current]==2 then it means there is a cycle. If we need to process a node which is processing then there is a loop.
        if(vis[current]==2)
            return true;
   		//If not then make it under processing and for its prerequistes check if there is a cycle.     
        vis[current]=2;
        for(int i=0;i<list[current].size();i++){
            if(vis[list[current][i]]!=1) // This line is skipping all the already processed adjacent nodes.
                if (isCyclic(list[current][i],list,vis))
                    return true;
        }
        vis[current] = 1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> vis(numCourses,0);
        vector<vector<int>> list(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        //Loop through for each node and check if visited or not. If Not then check if there is a cycle.
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0)
                if (isCyclic(i,list,vis))
                    return false;
        }
        
        return true;
    }
};
