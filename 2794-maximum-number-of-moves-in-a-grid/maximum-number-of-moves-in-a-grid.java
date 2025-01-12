class Solution {
    int util(int[][] grid, int m, int n, int i, int j){
        if(grid[i][j]==-1)return 0;
        
        // op1
        int op1 = 0,op2 = 0, op3 = 0;
        if(i-1>=0 && j+1<=n && grid[i-1][j+1]!=-1 && grid[i-1][j+1]>grid[i][j]){
            op1 = 1+util(grid,m,n,i-1,j+1);
        }
        if(j+1<=n &&  grid[i][j+1]!=-1 && grid[i][j+1]>grid[i][j]){
            op2 = 1+util(grid,m,n,i,j+1);
        }
        if(i+1<=m && j+1<=n &&  grid[i+1][j+1]!=-1 && grid[i+1][j+1]>grid[i][j]){
            op3 = 1+util(grid,m,n,i+1,j+1);
        }
        grid[i][j] = -1;
        return Math.max(op1,Math.max(op2,op3));
    }
    public int maxMoves(int[][] grid) {
        int m = grid.length-1, n = grid[0].length-1;
        int maxMovesCount = 0;
        for(int j=0;j<=m;j++){
            maxMovesCount = Math.max(util(grid, m, n,j,0),maxMovesCount) ;
        }
        
        return maxMovesCount;
    }
}