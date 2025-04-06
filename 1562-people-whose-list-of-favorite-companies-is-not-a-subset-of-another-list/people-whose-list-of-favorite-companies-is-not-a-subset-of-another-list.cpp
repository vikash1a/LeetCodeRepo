class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int nf = favoriteCompanies.size()-1;
        vector<int> resultIndex;
        vector<unordered_set<string>> vv(nf+1);
        for(int i=0;i<=nf;i++){
            for(int j=0;j<=favoriteCompanies[i].size()-1;j++){
                vv[i].insert(favoriteCompanies[i][j]);
            }
        }
        for(int i=0;i<=nf;i++){
            vector<string> fc = favoriteCompanies[i];
            bool result = false;
            for(int j=0;j<=nf;j++){
                if(j==i)continue;
                bool localResult = true;
                for(int k=0;k<=fc.size()-1;k++){
                    auto it = vv[j].find(fc[k]);
                    if(it==vv[j].end()){
                        localResult  = false;
                        break;
                    }
                }
                if(localResult){
                    result = true; break;
                }
            }
            if(!result)resultIndex.push_back(i);
        }
        return resultIndex;
    }
};
/*
brute force - O(n^2)

*/