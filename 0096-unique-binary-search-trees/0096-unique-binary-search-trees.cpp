class Solution {
public:
    int numTrees(int n) {
        if(n<=2)return n;
        vector<int> dp(n+1,0);
        dp[0]=1,dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++){
            int tempSum = 0;
            for(int j=1;j<=i;j++){
                tempSum += dp[j-1]*dp[i-j];
            }
            // cout<<i<<" "<<tempSum<<endl;
            dp[i] = tempSum;
        }
        return dp[n];
    }
};