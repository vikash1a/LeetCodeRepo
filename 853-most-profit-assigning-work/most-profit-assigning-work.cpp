class Solution {
public:
    int getProfit(int ability, vector<vector<int>>& difficultyProfit){
        int s = 0, e = difficultyProfit.size()-1;
        int profit = 0;
        while(s<=e){
            int m = s+(e-s)/2;
            if (difficultyProfit[m][0] <= ability){
                profit = difficultyProfit[m][1];
                s = m+1;
            }
            else e = m-1;
        }
        return profit;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int nd = difficulty.size()-1;
        int nw = worker.size()-1;
        vector<vector<int>> difficultyProfit(nd+1);
        for(int i=0;i<=nd;i++){
            difficultyProfit[i] = {difficulty[i], profit[i]};
        }

        sort(difficultyProfit.begin(), difficultyProfit.end());

        int localMax = 0;
        for(int i=0;i<=nd;i++){
            localMax = max(localMax, difficultyProfit[i][1]);
            difficultyProfit[i][1] = localMax;
            // cout<<i<<" "<<difficultyProfit[i][0]<<" "<<difficultyProfit[i][1]<<endl;
        }

        int totalProfit = 0;
        for(int i=0; i<=nw; i++){
            // int profit = getProfit(worker[i], difficultyProfit);
            // cout<<i<<" "<<profit<<endl;
            totalProfit += getProfit(worker[i], difficultyProfit);
        }
        return totalProfit;
    }
};
/*
brute force -O(n^2)
Optimised - O(nlog(n))
binary search on difficulty, store max profit for each difficulty. 
*/