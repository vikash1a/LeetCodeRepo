class Solution {
public:
    void floydWarshall(vector<vector<int>>& distV, int& n){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(distV[i][k]!=1e5 && distV[k][j]!=1e5){
                        distV[i][j] = min(distV[i][j], distV[i][k]+distV[k][j]);
                    }
                }
            }
        }
    }
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> pairCountV(n+1,0);
        vector<vector<int>> distanceV(n+1, vector<int>(n+1,1e5));
        for(int i=1;i<=n-1;i++){
            distanceV[i][i+1] = 1;
            distanceV[i+1][i] = 1;
        }
        distanceV[x][y] = 1;
        distanceV[y][x] = 1;
        floydWarshall(distanceV, n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j && distanceV[i][j]>=1 && distanceV[i][j]<=n){
                    pairCountV[distanceV[i][j]]+=1;
                }
            }
        }
        return vector<int>(pairCountV.begin()+1, pairCountV.end());
    }
};
/*
max Pair - (n)*(n-1)
use shortest distance from each node till n/2;


*/