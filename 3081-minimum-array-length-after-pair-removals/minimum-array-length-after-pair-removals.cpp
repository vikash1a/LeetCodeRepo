#include <vector>

using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int len = nums.size();
        int ans = len, i = 0, j = (len + 1) / 2;

        while (i < len / 2 && j < len) {
            if (nums[i] < nums[j]) {
                ans -= 2;
            }
            i++;
            j++;
        }
        return ans;
    }
};

/*
1,2,3,4 ->1, 4 -> 
1,1,2,2,3,3 -> 1 2 3 3-> 1 3 -> 
1,1 -> 
2,3,4,4,4 -> 2 4 4 -> 4

two option 
1,2,3,x -> 1,x
1,2,2,x -> 2,x
1,1,2,x -> 1,x
1,1,1,x->  1,x
*/