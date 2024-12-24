class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int nn = nums.size();
        map<int,int> mp;
        for(int k1: nums){
            if(mp.find(k1)==mp.end())mp[k1] = 1;
            else mp[k1]+=1;
        }
        int distinctCount = 0;
        int lastTaken = INT_MIN;
        for(auto it = mp.begin();it!=mp.end();it++){
            int ni = it->first, nc = it->second;
            int rangeStart = it->first-k, rangeEnd = it->first+k;
            int available = 0;
            if(lastTaken>=rangeStart){
                available = rangeEnd-lastTaken;
            }
            else available = rangeEnd-rangeStart+1;

            int taken = min(available,nc);
            
            if(lastTaken>=rangeStart){
                lastTaken = lastTaken+taken; 
            }
            else lastTaken = rangeStart+taken-1; 

            distinctCount += min(taken, nc);
            // cout<<ni<<" "<<nc<<" "<<taken<<" "<<available<<" "<<lastTaken<<endl;
        }
        return distinctCount;
    }
};
/*
5,7,7,7,8,8,9,9,10,10 
3,4,5,6,7,8,9,10,11,12
*/