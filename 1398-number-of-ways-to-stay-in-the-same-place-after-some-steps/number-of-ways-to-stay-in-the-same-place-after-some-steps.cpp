class Solution {
public:
    // recursive
    // int mod = 1e9+7;
    // void print( vector<vector<int>>& dp){
    //     for(vector<int> v: dp){
    //         for(int k: v){
    //             cout<<k<<"_";
    //         }cout<<endl;
    //     }
    // }
    // int util(int& arrLen, int i, int stepsCount,  vector<vector<int>>& dp){
    //     int currCount = 0;
    //     if(i<0 || i>=arrLen || stepsCount <0)return 0;
    //     else if(stepsCount == 0){
    //         if(i==arrLen-1)currCount = 1;
    //         else currCount = 0;
    //     }
    //     else{
    //         if(dp[i][stepsCount] != -1)return dp[i][stepsCount];

    //         // right
    //         currCount = (currCount%mod+util(arrLen, i+1, stepsCount-1,dp)%mod)%mod;

    //         // left
    //         currCount = (currCount%mod+util(arrLen, i-1, stepsCount-1,dp)%mod)%mod;

    //         // stay
    //         currCount = (currCount%mod+util(arrLen, i, stepsCount-1,dp)%mod)%mod;
    //     }
    //     cout<<i<<" "<<stepsCount<<" "<<currCount<<endl;
    //     dp[i][stepsCount] = currCount;      

    //     return currCount;
    // }
    // int numWays(int steps, int arrLen) {
    //     vector<vector<int>> dp(arrLen, vector<int>(steps+1,-1));
    //     int result = util(arrLen, arrLen-1, steps,dp);
    //     print(dp);
    //     return result;
    // }

    // bottom up
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps); // this step learnt from solution
        int mod = 1e9+7;
        vector<int> dp(arrLen,0);
        vector<int> dpTemp = dp;
        for(int i =0;i<=steps;i++){
            dpTemp = dp;
            for(int j=0;j<=arrLen-1;j++){
                if(j==0)dp[j] = 0;
                if(j==arrLen-1 && i==0)dp[j] = 1;
                else{
                    int first = 0, second= 0, third = 0;
                    first = dpTemp[j];
                    if((j+1) <= (arrLen-1))third = dpTemp[j+1];
                    if(j-1>=0)second = dpTemp[j-1];
                    dp[j] = ((first + second)%mod+third)%mod;
                }
                // cout<<i<<" "<<j<<" "<<dp[j]<<endl;
            }
        }
        return dp[arrLen-1];
    }
};
/*
1 -1 0
-1 1 0

brute force - 3^steps

*/