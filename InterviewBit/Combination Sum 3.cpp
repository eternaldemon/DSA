class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(9);
        for(int i=0;i<9;i++){
            arr[i] = i + 1;
        }
        vector<int> temp;
        createsubset(arr,n,0,temp,k);
        return result;
    }

    void createsubset(vector<int>&arr, int target, int index, vector<int>&temp, int k){
        if(target==0 && temp.size()==k){
            result.push_back(temp);
            return;
        }
        if(target<0)
            return;
        for(int i=index;i<arr.size();i++){
            if(arr[i]<=target){
                temp.push_back(arr[i]);
                createsubset(arr,target-arr[i],i+1,temp,k);
                temp.pop_back();
            }
        }
    }
};
