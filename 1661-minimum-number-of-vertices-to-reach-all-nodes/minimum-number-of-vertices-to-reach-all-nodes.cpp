class Solution {
public:
    void dfs( vector<vector<int>>& adj, vector<bool>& visited, int s){
        for(int i=0; i<=(int)adj[s].size()-1;i++){
            if(!visited[adj[s][i]]){
                visited[adj[s][i]] = true;
                dfs(adj,visited,adj[s][i]);
            }
        }
        return;
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj (n);
        vector<int> result;
        unordered_set<int> ust;
        for(int i=0;i<=edges.size()-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            ust.insert(edges[i][1]);
        }
        for(int i=0;i<=n-1;i++){
            if(ust.find(i)==ust.end()){
                result.push_back(i);
                visited[i] = true;
                dfs(adj, visited, i);
            }
        }
        for(int i=0;i<=n-1;i++){
            if(!visited[i]){
                result.push_back(i);
                visited[i] = true;
                dfs(adj, visited, i);
            }
        }
        return result;
    }
};
/*
- convert to adj list
- first start dfs with 
*/