class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        unordered_set<int> duplicatesSet;
        int nn = nums.size()-1;
        for(int i=0;i<=nn;i++){
            int j = i;
            while(nums[j]!=(j+1)){
                if(nums[j] == nums[nums[j]-1]){
                    
                    duplicatesSet.insert(nums[j]);
                    break;
                }
                swap(nums[j],nums[nums[j]-1]);
                // j = nums[j]-1;
            }
        }
        for(auto it: duplicatesSet){
            duplicates.push_back(it);
        }

        return duplicates;
    }
};
/*
4,3,2,7,8,2,3,1
7,3,2,4,8,2,3,1
3,3,2,4,8,2,7,1
2,3,3,4,8,2,7,1
-1,2,3,4,8,2,7,1
-1,2,3,4,1,2,7,8
1,2,3,4,-1,2,7,8
1,2,3,4,-1,-1,7,8

*/