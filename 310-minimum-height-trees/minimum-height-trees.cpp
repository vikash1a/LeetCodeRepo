class Solution {
public:
    // copied 
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Edge case
        if (n <= 2) {
            vector<int> centroids;
            for (int i = 0; i < n; ++i)
                centroids.push_back(i);
            return centroids;
        }

        // Build the graph using adjacency list
        vector<unordered_set<int>> neighbors(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            neighbors[u].insert(v);
            neighbors[v].insert(u);
        }

        // Initialize first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (neighbors[i].size() == 1)
                leaves.push_back(i);
        }

        // Trim leaves layer by layer until ≤ 2 nodes remain
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *neighbors[leaf].begin();
                neighbors[neighbor].erase(leaf);
                if (neighbors[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }
            leaves = newLeaves;
        }

        // Remaining nodes are centroids
        return leaves;
    }
};

// class Solution {
// public:
//     int getHeight(int n,  vector<vector<int>>& adj,
//     vector<bool>& visited, int s){
//         visited[s]=true;
//         int h = 0;
//         for(int i=0;i<=(int)adj[s].size()-1;i++){
//             if(!visited[adj[s][i]]){
//                 int lh = getHeight(n, adj, visited, adj[s][i]);
//                 h = max(h, lh);
//             }
//         }
//         return h+1;
//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         for(vector<int> edge: edges){
//             int s = edge[0], d = edge[1];
//             adj[s].push_back(d);
//             adj[d].push_back(s);
//         }
//         vector<int> heights(n);
        
//         // util(n,adj,heights,visited,0,0,0);
//         for(int i=0;i<=n-1;i++){
//             vector<bool> visited(n,false);
//             heights[i] = getHeight(n, adj, visited, i);
//         }
//         int maxHeight = *min_element(heights.begin(), heights.end());
//         vector<int> nodes;
//         for(int i=0;i<=n-1;i++){
//             // cout<<i<<" "<<heights[i]<<endl;
//             if(heights[i]==maxHeight)nodes.push_back(i);
//         }
//         return nodes;
//     }
// };
/*
op1
find height from each node 
TC * (V)*(V+E)

op2

*/