class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)
            return true;
        vector<int> indegree(numCourses,0);//Make Sure to make all indegree 0 when initializing.
        //Because if there is no prerequisite to any one course it should be pushed into the stack.
        stack<int> s;
        vector<int> topological(numCourses);
        int count=0;
        
        //The following loop creates a inorder degree vector for each course.
        for(int i =0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
        }
        //The following loop check for indegree==0 and pushes it to the stack.
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                s.push(i);
            }
        }
        //While stack is not empty pop the top element,increment count, then reduce the indegree for all courses having the popped element as a prerequisite.
        //The check if they have indegree==0 and accordingly push them onto the stack.
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            count++;
            topological.push_back(curr);
            cout<<curr<<endl;
            for(int i=0;i<prerequisites.size();i++){
                if(prerequisites[i][1]==curr){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]]==0){
                        s.push(prerequisites[i][0]);
                        }
                    }
            }
        }
        return count==numCourses;
    }
};
