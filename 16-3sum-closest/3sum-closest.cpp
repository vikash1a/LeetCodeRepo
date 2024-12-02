class Solution {
public:
    int findClosest(vector<int>& arr, int target, int start) {

        auto it = std::lower_bound(arr.begin()+start, arr.end(), target);

        // If the target is less than the smallest element
        if (it == (arr.begin()+start)) {
            return *it;
        }

        // If the target is greater than the largest element
        if (it == arr.end()) {
            return *(it - 1);
        }

        // Compare the closest elements on either side of the target
        int left = *(it - 1);
        int right = *it;
        return (std::abs(target - left) <= std::abs(target - right)) ? left : right;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int nn = (int)nums.size()-1;
        int sum = 0;
        int close = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0;i<=nn;i++){
            for(int j=i+1;j<=nn-1;j++){
                int toFind = target-(nums[i]+nums[j]);
                int kv = findClosest(nums, toFind, j+1);
                int tempSum = nums[i]+nums[j]+kv;
                if(abs(tempSum-target)<close){
                    close = abs(tempSum-target);
                    sum = tempSum;
                }
            }
        }
        return sum;
    }
};
/*
Brute force - N^3
Optimised - 
sort - nlog(n)
use binary search for third

-4 -1 1 2

*/