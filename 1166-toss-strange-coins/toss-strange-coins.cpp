class Solution {
public:
    double util(vector<double>& prob, int target, int index, vector<vector<double>>& dp){
        if(target<0)return 0;
        if(index > prob.size()-1)return target==0?1:0;
        if(dp[target][index]!=-1)return dp[target][index];

        double prob1 = prob[index]*util(prob, target-1, index+1, dp);
        double prob2 = (1-prob[index])*util(prob, target, index+1,dp);
        dp[target][index] = prob1+prob2;
        return dp[target][index];
    }
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<vector<double>> dp(vector<vector<double>>(target+1, vector<double>(prob.size(), -1)));
        return util(prob, target, 0, dp);
    }
};