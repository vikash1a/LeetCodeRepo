class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nn = nums.size()-1;
        int i=0,j=0, ans =0;
        while(i<=nn){
            int temp = i;
            while(i+1<=nn && nums[i+1] == nums[i]){
                i++;   
            }
            nums[j] = nums[i];
            j++;
            i++;
            ans++;
        }
        return ans;
        
    }
};