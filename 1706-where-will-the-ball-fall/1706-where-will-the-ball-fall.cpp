class Solution {
public:
    int check(vector<vector<int>>& grid,int i, int j, int nr,int nc){
        if(i==nr+1)return j;
        if(grid[i][j]==1){
            if(j+1 > nc)return -1;
            if(grid[i][j+1]==1){
                return check(grid,i+1,j+1,nr,nc);
            }
            else return -1;
        }
        else{
            if(j-1 < 0)return -1;
            if(grid[i][j-1]==-1){
                return check(grid,i+1,j-1,nr,nc);
            }
            else return -1;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int nr = grid.size()-1, nc = grid[0].size()-1;
        vector<int> ans(nc+1,0);
        for(int i=0;i<=nc;i++){
            ans[i] = check(grid,0,i,nr,nc);
        }
        return ans;
    }
};