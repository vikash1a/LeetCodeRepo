class Solution {
public:
    void shortestDistance(vector<vector<int>>& adjV, int& n, int s, vector<vector<int>>& distanceV){
        // intialise a priority queue 
        queue<int> qu;
        vector<bool> visited(n+1,false);
        qu.push(s);
        visited[s] = true;
        int level = 0;
        while(!qu.empty()){
            queue<int> quTemp;
            while(!qu.empty()){
                int front = qu.front();
                qu.pop();
                distanceV[s][front] = min(distanceV[s][front], level);
                distanceV[front][s] = min(distanceV[front][s], level);
                visited[front] = true;
                for(int i=0;i<=adjV[front].size()-1;i++){
                    int d = adjV[front][i];
                    if(!visited[d])quTemp.push(d);
                }
            }
            qu = quTemp;
            level+=1;
        }
    }
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> pairCountV(n+1,0);
        vector<vector<int>> adjV(n+1);
        for(int i=1;i<=n-1;i++){
            adjV[i].push_back(i+1);
            adjV[i+1].push_back(i);
        }
        adjV[x].push_back(y);
        adjV[y].push_back(x);

        vector<vector<int>> distanceV(n+1, vector<int>(n+1,INT_MAX));
        for(int i=1;i<=n;i++){
            shortestDistance(adjV, n, i,distanceV);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(distanceV[i][j]>=1 && distanceV[i][j]<=INT_MAX){
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