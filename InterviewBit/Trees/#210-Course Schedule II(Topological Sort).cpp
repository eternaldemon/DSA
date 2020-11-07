class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Make Sure to make all indegree 0 when initializing.
        //Because if there is no prerequisite to any one course it should be pushed into the stack.
		vector<int> indegree(numCourses,0);
        int length = prerequisites.size();
        vector<int> result;
        stack<int> s;
        int count=0;
        //The following loop creates a inorder degree vector for each course.
        for(int i=0;i<length;i++){
            indegree[prerequisites[i][0]]++;
        }
        //The following loop check for indegree==0 and pushes it to the stack.
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                s.push(i);
        }
        //While stack is not empty pop the top element,increment count, then reduce the indegree for all courses having the popped element as a prerequisite.
        //The check if they have indegree==0 and accordingly push them onto the stack.
        while(!s.empty()){
            int curr=s.top();
            s.pop();
            count++;
            result.push_back(curr);
            for(int i=0;i<length;i++){
                if(prerequisites[i][1]==curr){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]]==0)
                        s.push(prerequisites[i][0]);
                }
            }
        }
        if(count==numCourses)
            return result;
        else
            return vector<int>();
    }
};
