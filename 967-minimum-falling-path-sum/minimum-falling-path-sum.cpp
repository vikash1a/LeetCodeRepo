class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int nm = matrix.size()-1;
        vector<int>dp;
        for(int i=0;i<=nm;i++)dp.push_back(matrix[0][i]);
        for(int i=1;i<=nm;i++){
            vector<int>dpTemp = dp;
            for(int j=0; j<=nm; j++){
                int result = matrix[i][j];
                int op1=INT_MAX, op2=INT_MAX, op3=INT_MAX;
                op1 = dp[j];
                if(j-1>=0)op2 = dp[j-1];
                if(j+1<=nm)op3 = dp[j+1];
                result += min(op1, min(op2, op3));
                dpTemp[j] = result;
            }
            dp = dpTemp; 
        }
        int minValue = INT_MAX;
        for(int i=0;i<=nm;i++)minValue = min(minValue, dp[i]);
        return minValue;
    }
};