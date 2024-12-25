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
};
/*
2-> 6
3-> 6
6-> 3,2
*/