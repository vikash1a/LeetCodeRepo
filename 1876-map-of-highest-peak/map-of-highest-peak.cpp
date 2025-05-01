class Solution {
public:
    void process(vector<vector<int>>& result,  priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> >& pq, int v, int r, int c){
        if(r>=0 && r<=result.size()-1 && c>=0 && c<=result[0].size()-1){
            if(result[r][c]==-1){
                // cout<<r<<" "<<c<<" "<<v<<endl;
                result[r][c] = v+1;
                pq.push({v+1,r,c});
            }
        }
        
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size()-1;
        int n = isWater[0].size()-1;
        vector<vector<int>> result = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        for(int i=0;i<=m;i++){
            for(int j=0; j<=n; j++){
                if(isWater[i][j]==1){
                    result[i][j] = 0;
                    pq.push({0,i,j});
                }
            }
        }
        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();
            int r = top[1], c = top[2], v= top[0];
            process(result, pq,v, r-1, c);
            process(result, pq,v, r+1, c);
            process(result, pq,v, r, c-1);
            process(result, pq,v, r, c+1);
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