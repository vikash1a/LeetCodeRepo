class Solution {
    fun util(n:Int, dp: MutableList<Int>): Int{
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        var result = n;
        for(i in 1..n){
            val firstHalf = util(i-1, dp);
            val secondHalf = util(n-i,dp);
            result = min(result,1+ max(i-1,secondHalf));
        }
        dp[n] = result;
        return result;
    }
    fun twoEggDrop(n: Int): Int {
        val dp = MutableList(n+1){-1};
        return util(n,dp);
    }
}
/*
 int util(int n, vector<int>& dp){
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        int result = n;
        for(int i=1;i<=n;i++){
            int firstHalf = util(i-1, dp);
            int secondHalf = util(n-i,dp);
            result = min(result,1+ max(i-1,secondHalf));
        }
        dp[n] = result;
        return result;
    }
    int twoEggDrop(int n) {
       vector<int> dp(n+1,-1);
       return util(n, dp);
    }
 */