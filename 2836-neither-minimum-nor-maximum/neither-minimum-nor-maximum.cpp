class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int minE = *min_element(nums.begin(), nums.end());
        int maxE = *max_element(nums.begin(), nums.end());
        for(int k: nums){
            if(k!=minE && k!=maxE)return k;
        }
        return -1;
    }
};