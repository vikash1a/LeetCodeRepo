class Solution {
public:

    long long minimumCost(string s) {
        int n = s.size()-1;
        vector<long long> leftC(n+1,0);
        vector<long long> rightC(n+1,0);
        for(int i=1;i<=n;i++){
            leftC[i] = leftC[i-1];
            if(s[i]!=s[i-1]) leftC[i]+=i;
        }
        for(int i=n-1;i>=0;i--){
            rightC[i] = rightC[i+1];
            if(s[i]!=s[i+1]) rightC[i]+=n-i;
        }
        long long minCost = LONG_MAX;
        for(int i=0;i<=n;i++){
            minCost = min(minCost,leftC[i]+rightC[i]);
        }
        return minCost;

    }
};
/*

util(s)
    cost
    for i : 0 to n-1
        invert(s,0,i)
        cost1 = i+1+util(s)

        invert(s,i+1,n)
        cost2 = n-i+util(s)
        cost = min(cost, min(cost1, cost2))
    return cost

util(s, si, ei, isInverted)
    if all char same:
        return {0, char};
    totalCost;
    for i : 0 to n
        // option 1
        cost1 = i+1
        cost11 = util(s,si,i,!isInverted)
        cost12 = util(s,i+1,ei,isInverted)
        if(cost11.second == cost12.second){
            cost1+= cost11+cost12
        }
        else cost1 = INT_MAX;

        // option 2 
        cost2 = ei-i
        cost21 = util(s,si,i,isInverted)
        cost22 =  util(s,i+1,ei,!isInverted)
        if(cost21.second == cost22.second){
            cost2+= cost21+cost22
        }
        else cost2 = INT_MAX;

    return {totalCost, char}

010101 - 1
110101 - 2
000101 - 2
000110 - 2
000111 - 1
*/