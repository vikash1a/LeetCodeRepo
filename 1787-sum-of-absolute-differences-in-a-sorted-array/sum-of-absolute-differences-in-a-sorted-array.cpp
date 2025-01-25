class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int nn = nums.size()-1;
        vector<pair<int,int>> vp(nn+1);
        int totalSum =0;
        for(int i=0;i<=nn;i++){
            vp[i] = {nums[i],i};
            totalSum+=nums[i];
        }
        sort(nums.begin(), nums.end());
        vector<int> sumDiff(nn+1);
        
        int leftSum = 0, rightSum = totalSum;
        for(int i=0;i<=nn;i++){
            if(i-1>=0)leftSum+=vp[i-1].first;
            rightSum-=vp[i].first;
            sumDiff[vp[i].second] = (long)rightSum - (long)((nn-i)*vp[i].first)+(long)((i)*vp[i].first)- (long)leftSum;
        }
        return sumDiff;
    }
};
/*
brute force - O(n^2)

*/