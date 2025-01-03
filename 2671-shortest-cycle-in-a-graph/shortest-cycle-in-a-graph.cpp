class Solution {
public:
    // copied
    int ans = INT_MAX;

    void bfs(int src,vector<int> adj[],int n){
            vector<int> distance(n,(1e9));
            vector<int> parent(n, -1);
            
            queue<int> q;
            distance[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto neigh : adj[node]) {
                    if (distance[neigh] == (int)(1e9)) {
                        distance[neigh] = 1 + distance[node];
                        parent[neigh] = node;
                        q.push(neigh);
                }
                else if (parent[node] != neigh && parent[neigh] != node)
                    ans = min(ans, distance[neigh] + distance[node] + 1);
                }
            }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {

        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      
        for (int i = 0; i < n; i++)
        {
            bfs(i,adj,n);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
    // self 82/88 case passed
    // void util(vector<vector<int>>& adj, vector<bool>& visited, 
    //     map<int,int>& recStack, int u, int parent, int& shortestCycle){
    //     visited[u] = true;
    //     recStack[u] = recStack.size()+1;
    //     for(int i=0;i<=(int)adj[u].size()-1;i++){
    //         if(!visited[adj[u][i]]){
    //             util(adj,visited,recStack,adj[u][i],u,shortestCycle);
    //         }
    //         else if(adj[u][i] != parent 
    //             && recStack.find(adj[u][i])!=recStack.end())
    //         {
    //             int cycleLength = recStack.size()+1-recStack[adj[u][i]];
    //             shortestCycle = min(shortestCycle, cycleLength);
    //         }
    //     }
    //     recStack.erase(u);

    // }
    // int findShortestCycle(int n, vector<vector<int>>& edges) {
    //     int shortestCycle = INT_MAX;
    //     vector<vector<int>>  adj(n);
    //     for(vector<int> edge: edges){
    //         adj[edge[0]].push_back(edge[1]);
    //         adj[edge[1]].push_back(edge[0]);
    //     }
    //     vector<bool> visited(n, false);
    //     map<int,int> recStack;
    //     for(int i=0;i<=n-1;i++){
    //         // if(!visited[i]){
    //             util(adj,visited,recStack,i,-1,shortestCycle);
    //             recStack.clear();
    //             visited = vector<bool>(n, false);
    //         // }
    //     }
    //     if(shortestCycle == INT_MAX)return -1;
    //     return shortestCycle;
    // }
};