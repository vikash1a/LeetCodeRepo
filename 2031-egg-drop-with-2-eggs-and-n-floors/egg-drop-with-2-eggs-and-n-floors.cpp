class Solution {
public:
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
};
/*
1-> 1
2 -> 2
1st breaks -> 1
1st not break -> 
    second not break -> 0
    second break -> 1
3 -> 2
4-> 3
5 -> 
10 -> 5,4,5
20 -> 10, 9,10


*/