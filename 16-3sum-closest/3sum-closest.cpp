class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nn = (int)nums.size()-1;
        int sum = 0;
        int close = INT_MAX;
        for(int i=0;i<=nn;i++){
            for(int j=i+1;j<=nn;j++){
                for(int k=j+1;k<=nn;k++){
                    int tempSum = nums[i]+nums[j]+nums[k];
                    if(abs(tempSum-target)<close){
                        close = abs(tempSum-target);
                        sum = tempSum;
                    }
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



*/