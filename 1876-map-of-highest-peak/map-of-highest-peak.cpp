class Solution {
public:
    void process(vector<vector<int>>& result,  queue< vector<int>>& qu,  int v, int r, int c){
        if(r>=0 && r<=result.size()-1 && c>=0 && c<=result[0].size()-1){
            if(result[r][c]==-1){
                // cout<<r<<" "<<c<<" "<<v<<endl;
                result[r][c] = v+1;
                qu.push({v+1,r,c});
            }
        }
        
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size()-1;
        int n = isWater[0].size()-1;
        vector<vector<int>> result = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        queue< vector<int> > qu;
        for(int i=0;i<=m;i++){
            for(int j=0; j<=n; j++){
                if(isWater[i][j]==1){
                    result[i][j] = 0;
                    qu.push({0,i,j});
                }
            }
        }
        while(!qu.empty()){
            vector<int> front = qu.front();
            qu.pop();
            int r = front[1], c = front[2], v= front[0];
            process(result, qu,v, r-1, c);
            process(result, qu,v, r+1, c);
            process(result, qu,v, r, c-1);
            process(result, qu,v, r, c+1);
        }
        return result;
    }
};
/*
Attempt 1
DFS starting water cell
value
    if all item filled then min+1
    else min+1
this would not work as we want to process min value node first

Attempt 2
Put all water value in priority queue
for all adjacent node
    value = value+1
    put in pq

*/