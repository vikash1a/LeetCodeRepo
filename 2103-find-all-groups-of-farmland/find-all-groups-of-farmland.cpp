class Solution {
public:
    void bfs(vector<vector<int>>& land, vector<vector<bool>>& visited,
    int &m, int &n, int r, int c, vector<int>& farmLand){
        if(r>m || c>n || visited[r][c] || land[r][c]==0)return;
        visited[r][c] = true;
        if(r>=farmLand[0] && c>=farmLand[1]){
            farmLand = {r,c};
        }
        // right
        bfs(land,visited,m,n,r+1,c,farmLand);
        // bottom
        bfs(land,visited,m,n,r,c+1,farmLand);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> groups;
        int m = land.size()-1, n = land[0].size()-1;
        vector<vector<bool>> visited(m+1, vector<bool>(n+1, false));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(!visited[i][j] && land[i][j]==1){
                    vector<int> localFarmLand = {i,j};
                    bfs(land,visited,m,n,i,j,localFarmLand);
                    groups.push_back({i,j,localFarmLand[0],localFarmLand[1]});
                }
            }
        }
        return groups;
    }
};