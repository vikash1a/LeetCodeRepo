class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int startIndex =-1, endIndex =-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]==target){
                e=m-1;
                startIndex = m;
            }
            else if(nums[m]<target)s=m+1;
            else e=m-1;
        }
        s = 0, e = nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]==target){
                s=m+1;
                endIndex = m;
            }
            else if(nums[m]<target)s=m+1;
            else e=m-1;
        }
        return {startIndex, endIndex};
    }
};