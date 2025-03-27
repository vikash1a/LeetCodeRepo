class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int na = arrays.size()-1;
        // map<int,int> unmp_min;
        map<int,int> unmp_max;
        for(vector<int> v: arrays){
            int min_e = v[0], max_e = v[v.size()-1];
            // if(unmp_min.find(min_e)!=unmp_min.end())unmp_min[min_e] += 1;
            // else unmp_min[min_e] = 1;
            if(unmp_max.find(max_e)!=unmp_max.end())unmp_max[max_e] += 1;
            else unmp_max[max_e] = 1;
        }
        // for(auto it: unmp_max){
        //     cout<<it.first<<" - "<<it.second<<endl;
        // }
        int maxDistanceValue = 0;
        for(vector<int> v: arrays){
            int min_e = v[0], max_e = v[v.size()-1];
            auto it = unmp_max.rbegin();
            // cout<<it->first<<" _ "<<it->second<<endl;
            if(it->first == max_e && it->second == 1){
                it++;
                // cout<<it->first<<" -> "<<it->second<<endl;
                maxDistanceValue = max(maxDistanceValue,it->first - min_e);
            }
            else maxDistanceValue = max(maxDistanceValue, it->first - min_e);
            // cout<<it->first<<" - "<<min_e<<endl;
        }
        return maxDistanceValue;
    }
};
/*
brute force - O(n^2)
op1 - O(n), O(n)


*/