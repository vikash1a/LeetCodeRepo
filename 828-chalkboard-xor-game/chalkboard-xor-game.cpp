class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for(int k: nums)x^=k;
        return x==0 || nums.size()%2 == 0;
    }
};
/*
0 0 -> 0
0 1-> 1
1 0 -> 1
1 1 -> 1

no element left 
element left have even number of duplicate
last element is 0 

*/