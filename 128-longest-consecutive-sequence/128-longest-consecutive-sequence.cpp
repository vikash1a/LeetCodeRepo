class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> ust;
        for(int k : nums)ust.insert(k);
        for(int k : nums){
            if(ust.find(k)==ust.end())continue;
            ust.erase(k);
            int count =1;
            int i = k+1;
            while(ust.find(i)!=ust.end()){
                ust.erase(i);
                i++;
                count++;
                
            }
            i = k-1;
            while(ust.find(i)!=ust.end()){
                ust.erase(i);
                i--;
                count++;
            }
            ans = max(ans,count);
            // cout<<k<<" "<<count<<endl;
        }
        return ans;
    }
};