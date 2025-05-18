class Solution {
public:
    string getKey(vector<int> v){
        string s = "";
        for(int k: v)s+=to_string(k);
        return s;
    }
    bool util(vector<int> piles, unordered_map<string, bool>& unmp){
        bool isTurnLeft = false;
        bool result = false;
        sort(piles.begin(), piles.end());
        string key = getKey(piles);
        if(unmp.find(key)!=unmp.end())return unmp[key];
        for(int i=0;i<=piles.size()-1;i++){
            if(piles[i]>=1){
                isTurnLeft = true;
                for(int j=1;j<=piles[i];j++){
                    piles[i]-=j;
                    if(!util(piles, unmp)){
                        result = true; break;
                    }
                    piles[i]+=j;
                }
            }
        }
        if(!isTurnLeft) result = false;
        unmp[key] = result;
        return result;
    }
    bool nimGame(vector<int>& piles) {
        unordered_map<string,bool> unmp;
        return util(piles, unmp);
    }
};
/*


*/