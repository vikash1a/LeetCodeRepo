class Solution {
public:
    int mod = 1e9+7;
    int dfs(vector<vector<int>>& grid, int& m, int &n, vector<vector<int>>& dp, int i, int j){
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j] = 1;
        if(i-1>=0 && grid[i][j]>grid[i-1][j]){
            dp[i][j]+=dfs(grid,m,n,dp,i-1,j)%mod;
            dp[i][j]%=mod;
        }
        if(i+1<=m && grid[i][j]>grid[i+1][j]){
            dp[i][j]+=dfs(grid,m,n,dp,i+1,j)%mod;
             dp[i][j]%=mod;
        }
        if(j-1>=0 && grid[i][j]>grid[i][j-1]){
            dp[i][j]+=dfs(grid,m,n,dp,i,j-1)%mod;
             dp[i][j]%=mod;
        }
        if(j+1<=n && grid[i][j]>grid[i][j+1]){
            dp[i][j]+=dfs(grid,m,n,dp,i,j+1)%mod;
             dp[i][j]%=mod;
        }
        // cout<<i<<" "<<j<< " "<<dp[i][j]<<endl;
        return  dp[i][j];
    }
    int countPaths(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size()-1, n = grid[0].size()-1;
        vector<vector<int>> dp (m+1, vector<int>(n+1,-1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                count+=dfs(grid,m,n,dp,i,j)%mod;
                count%=mod;
            }
        }
        return count;
    }
};
/*
Brute force - N^N
DFS using visited array 
*/