//It is on LeetCode
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());//Sorting is important
        createsubset(candidates, target, 0, temp);
        set<vector<int>> s;
        for(auto i:result)
            s.insert(i);
        set<vector<int>>::iterator it;
        result.clear();
        for(it=s.begin();it!=s.end();it++){
         result.push_back(*it);
        }
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
                createsubset(candidates,target-candidates[i],i+1,temp);
                temp.pop_back();
                }
            }
    }
};
