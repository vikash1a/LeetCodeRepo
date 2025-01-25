class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int nn = nums.size()-1;
        int totalSum =0;
        for(int i=0;i<=nn;i++){
            totalSum+=nums[i];
        }
        vector<int> sumDiff(nn+1);
        
        int leftSum = 0, rightSum = totalSum;
        for(int i=0;i<=nn;i++){
            if(i-1>=0)leftSum+=nums[i-1];
            rightSum-=nums[i];
            sumDiff[i] = (long)rightSum - (long)((nn-2*i)*nums[i])- (long)leftSum;
        }
        return sumDiff;
    }
};
/*
brute force - O(n^2)

*/