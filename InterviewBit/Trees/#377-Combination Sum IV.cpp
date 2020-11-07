class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1,0);
        dp[0] = 1;
        //i denotes dp array index and target to reach in subproblem
        //j denotes index of given nums array
        // Draw state space tree to get a better perspective of the problem
        for(int i=1;i<target+1;i++){
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j])
                    dp[i] = dp[i] + dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
