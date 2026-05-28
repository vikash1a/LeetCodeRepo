class Solution {
public:
    void print(vector<int> & v){
        for(int k: v){
            cout<<k<<" ";
        }cout<<endl;
    }
    vector<int> mergeHelper(vector<int>& v1, vector<int>& v2){
        int n1= v1.size()-1, n2 = v2.size()-1;
        if(n1==-1) {
            sort(v2.begin(), v2.end());
            return v2;
        }
        if(n2==-1)  {
            sort(v1.begin(), v1.end());
            return v1;
        }
        // cout<<"debug 1"<<endl;
        vector<int> v3(n1+n2+2);
        int i1=0,i2=0,i3=0;
        while(i1<=n1 && i2<=n2){
            // cout<<v1[i1]<<" "<<v2[i2]<<" "<<v3[i3]<<endl;
            if(v1[i1]<=v2[i2]){
                v3[i3] = v1[i1]; i1++; i3++;
            }
            else{
                v3[i3] = v2[i2]; i2++; i3++;
            }
            
        }
        while(i1<=n1){
            v3[i3] = v1[i1]; i1++; i3++;
        }
        while(i2<=n2){
            v3[i3] = v2[i2]; i2++; i3++;
        }
        return v3;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int nn = nums.size()-1;
        vector<int> result(nn+1,0);
        int partitionIndex = -1;
        vector<int> v1,v2;
        for(int i=0;i<=nn;i++){
            result[i] = (nums[i])*(nums[i]);
            if(partitionIndex==-1)v1.push_back(result[i]);
            else v2.push_back(result[i]);
            if((partitionIndex==-1 && i+1<=nn) && (nums[i]<=0 && nums[i+1]>0)){
                partitionIndex = i;
            }
        }
        reverse(v1.begin(), v1.end());
        // print(v1);print(v2);
        vector<int> v3 = mergeHelper(v1,v2);
        return v3;
    }
};
/*
- Approch 1
    - sqaure and then merge the two unsroted part
    - TC - O(n), SC - O(n)

*/