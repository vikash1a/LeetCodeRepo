class Solution {
public:
    long util(vector<vector<int>>& costs, int startIndex, int firstCityCount,
    vector<vector<long>>& dp){
        int n = costs.size()/2;
        int secondCityCount = startIndex-firstCityCount;

        // cout<<startIndex<<" "<<firstCityCount<<" "<<secondCityCount<<endl;

        if(firstCityCount==n && secondCityCount==n)return 0;
        if(startIndex > 2*n-1)return INT_MAX;
        if(abs(firstCityCount-secondCityCount)> n) return INT_MAX;

        if(dp[startIndex][firstCityCount]!=-1)return dp[startIndex][firstCityCount];

        long cost1, cost2;
        // option 1 fly to first city
        cost1 = (long)(costs[startIndex][0])+
        (long)util(costs,startIndex+1,firstCityCount+1,dp);

        // option2
        cost2 = (long)costs[startIndex][1]+
        (long)util(costs,startIndex+1,firstCityCount,dp);
        
        // cout<<startIndex<<" "<<firstCityCount<<" "<<secondCityCount<<" "<<cost1<<" "<<cost2<<endl;
        long cost =  min(cost1, cost2);
        dp[startIndex][firstCityCount] =  cost;
        return cost;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<long>> dp = vector<vector<long>>(n+1, vector<long>(n+1, -1));
        return (int)util(costs, 0, 0,dp);
    }
};
/*
Brute force - 2^n


*/