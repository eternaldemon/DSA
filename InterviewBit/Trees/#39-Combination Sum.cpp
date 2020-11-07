class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());//Sorting is important
        createsubset(candidates, target, 0, temp);
        return result;
        
    }
void createsubset(vector<int>& candidates, int target, int index, vector<int>& temp){
        if(target==0){
            result.push_back(temp);
            return;
        }
        else if(target<0)
            return;
        
        for(int i=index;i<candidates.size();i++){
            if (candidates[i]<=target){
                temp.push_back(candidates[i]);
                createsubset(candidates,target-candidates[i],i,temp);
                temp.pop_back();
                }
            }
    }
};
