class Solution {
public:

    // copied from chatgpt
    const int MOD = 1e9 + 7;

    int specialPermutations(vector<int>& nums) {
        int n = nums.size();
        int FULL_MASK = (1 << n) - 1;

        // DP table: dp[mask][i] = # of ways to form a special permutation ending at nums[i]
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));

        // Base case: each number can start a permutation
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = 1;
        }

        // Fill the DP table
        for (int mask = 1; mask <= FULL_MASK; ++mask) {
            for (int i = 0; i < n; ++i) {
                // If nums[i] is not in the current mask, skip
                if (!(mask & (1 << i))) continue;

                // Try adding nums[j] to the permutation
                for (int j = 0; j < n; ++j) {
                    if (mask & (1 << j)) continue; // nums[j] is already in the mask

                    // Check if the transition is valid
                    if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                        dp[mask | (1 << j)][j] = (dp[mask | (1 << j)][j] + dp[mask][i]) % MOD;
                    }
                }
            }
        }

        // Sum all permutations represented by full masks
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + dp[FULL_MASK][i]) % MOD;
        }

        return result;
    }


    int specialPerm(vector<int>& nums) {
        return specialPermutations(nums);
    }

    // self
    /*
    void dfs(int current, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int& pathCount, int totalNodes) {
        // If the current path visits all nodes, count it as a valid path
        if (visited.size() == totalNodes) {
            pathCount++;
            return;
        }

        // Explore all neighbors of the current node
        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) { // If the neighbor has not been visited
                visited.insert(neighbor);
                dfs(neighbor, graph, visited, pathCount, totalNodes);
                visited.erase(neighbor); // Backtrack
            }
        }
    }

    int countAllHamiltonianPaths(unordered_map<int, vector<int>>& graph) {
        int totalPaths = 0;
        int totalNodes = graph.size(); // Number of vertices in the graph

        // Iterate over all nodes and start DFS from each node
        for (auto& [startNode, _] : graph) {
            unordered_set<int> visited;
            visited.insert(startNode); // Start the path with the current node
            dfs(startNode, graph, visited, totalPaths, totalNodes);
        }

        return totalPaths;
    }


    int specialPerm(vector<int>& nums) {
        int ns = nums.size()-1;
        int totalCount = 0;
        unordered_map<int,vector<int>> unmp;
        for(int i=0; i<=ns; i++){
            for(int j=i+1;j<=ns;j++){
                if(nums[i]%nums[j] == 0 || nums[j]%nums[i] == 0){
                    if(unmp.find(nums[i])==unmp.end())unmp[nums[i]] = {nums[j]};
                    else unmp[nums[i]].push_back(nums[j]);
                    if(unmp.find(nums[j])==unmp.end())unmp[nums[j]] = {nums[i]};
                    else unmp[nums[j]].push_back(nums[i]);
                }
            }
        }
        totalCount = countAllHamiltonianPaths(unmp);
        return totalCount;
    }
    */
};
/*
2-> 6
3-> 6
6-> 3,2
*/