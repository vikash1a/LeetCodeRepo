class Solution {
public:
    long long util(vector<int>& nums, int s,  bool isEven, vector<vector<long long>>& dp){
        if(s == nums.size()) return 0;
        if(dp[s][isEven]!=0)return dp[s][isEven];
        // keep 
        long long update = 0;
        if(isEven)update = nums[s];
        else update = -nums[s];
        long long op1 = update + util(nums,s+1, !isEven,dp);

        // do not keep
        long long op2 = util(nums,s+1, isEven,dp);
        dp[s][isEven] = max(op1,op2);
        return dp[s][isEven];
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2,0));
        return util(nums, 0,true, dp);
    }
};
/*
Brute force -  (2^n)*n
All possible subsequnce - (2^n)

*/