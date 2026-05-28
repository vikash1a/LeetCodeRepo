class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return ;
        int i1=0; int i2=0;
        while(i1<=m-1 && i2<=n-1){
            // cout<<i1<<" "<<i2<<endl;
            if(nums1[i1]>=nums2[i2]){
                swap(nums1[i1], nums2[i2]);
                int tempI2 = i2;
                while((tempI2+1<=n-1) && (nums2[tempI2]>nums2[tempI2+1])){
                    swap(nums2[tempI2], nums2[tempI2+1]);
                    tempI2++;
                }
            }
            i1++;
            
        }
        while(i1<=m+n-1){
            nums1[i1] = nums2[i2];
            i1++;i2++;
            int tempI2 = i2;
            while((tempI2+1<=n-1) && (nums2[tempI2]>nums2[tempI2+1])){
                swap(nums2[tempI2], nums2[tempI2+1]);
                tempI2++;
            }
        }
        return ;
    }
};
/*
- Approach 1
    - make a complete array and sort 
        - nlogn
- Approach 
    - target o(n)
    - 

- 
1,4,8
2,3,5,9,-,-,-

2,4,8
1,3,5,9,-,-,-

3,4,8
1,2,5,9,-,-,-

5,4,8
1,2,3,9,-,-,-

4,5,8
1,2,3,9,-,-,-

5,9,8
1,2,3,4,-,-,-

8,9
1,2,3,4,5,-,-

1,5,6
2,4,3

1,2,6
4,5,3

*/