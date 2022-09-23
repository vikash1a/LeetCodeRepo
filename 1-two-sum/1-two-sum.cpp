class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ust;
        for(int i=0;i<=nums.size()-1;i++){
            auto it = ust.find(target - nums[i]);
            if(it!=ust.end()){
                return {it->second,i};
            }
            ust.insert({nums[i],i});
        }
        return {};
        
    }
};