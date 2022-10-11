class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int nn = nums.size()-1;
        if(nn+1 < 3) return false;
        
        map<int,int> mp;
        int minVal = nums[0]; 
        
        for(int i=2;i<=nn;i++){
            if(mp.find(nums[i])==mp.end()){
                 mp[nums[i]]=1;
            }
            else mp[nums[i]]+=1;
        };
        // for(auto it : mp){
        //     cout<<it.first<<"-"<<it.second<<endl;
        // }
        for(int i=1;i<=nn-1;i++){
            minVal = min(minVal,nums[i-1]);
            // cout<<nums[i]<<" "<<minVal<<" "<<mp.rbegin()->first<<endl;
            if(nums[i]>minVal && nums[i]<mp.rbegin()->first)return true;
            mp[nums[i+1]]-=1;
            if(mp[nums[i+1]]<=0)mp.erase(nums[i+1]);
            
        }
        return false;
    }
};