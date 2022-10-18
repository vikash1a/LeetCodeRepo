class Solution {
public:
    int jump(vector<int>& nums) {
        int nn = nums.size()-1;
        if(nn+1 == 1)return 0;
        vector<int> jumpCount (nn+1,1e6);
        jumpCount[0]=0,jumpCount[1]=1;
        for(int i=0;i<=nn;i++){
            for(int j=i+1;j<=i+nums[i] && j<=nn;j++){
                jumpCount[j] = min(jumpCount[j], jumpCount[i]+1);
                // cout<<i<<" "<<j<<" "<<jumpCount[j]<<endl;
            }
        }
        return jumpCount[nn];
    }
};
/*
2 3 1 1 4
0 1 1 1 1

0 1 1 2 2

2 3 0 1 4
0 1 1 2 2

*/