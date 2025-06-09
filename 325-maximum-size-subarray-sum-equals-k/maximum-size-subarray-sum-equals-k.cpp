class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size()-1;
        unordered_map<long,int> unmp;
        int maxLen = 0;
        int sum = 0;
        unmp[0] = -1;
        for(int l = 0;l<=n;l++){
            sum+=nums[l];
            if(unmp.find(sum)==unmp.end())unmp[sum] = l;
            long diff = (long)sum-(long)k;
            if(unmp.find(diff)!=unmp.end()){
                maxLen = max(maxLen, abs(l-unmp[diff]));
            }
        }
        return maxLen;
    }
};
/*
BF - O(N^2)

*/