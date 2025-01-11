class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size()-1, n = grid[0].size()-1;
        vector<int> nr(m+1,0), nc(n+1,0);
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++) if(grid[i][j]==1)nr[i]+=1;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) if(grid[j][i]==1)nc[i]+=1;
        }
        vector<vector<int>> diff(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++) diff[i][j] = 2*(nr[i])-(m+1) + 2*(nc[j])-(n+1);
        }
        return diff;
    }
};