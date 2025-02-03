class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int np = pairs.size()-1;
        sort(pairs.begin(), pairs.end());
        vector<int> countV(np+1,1);
        for(int i=1; i<=pairs.size()-1; i++){
            // cout<<pairs[i-1][0]<<" "<<pairs[i-1][1]<<" "<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
            for(int j=0;j<=i-1;j++){
                if(pairs[i][0]> pairs[j][1]){
                   countV[i] = max(countV[i], countV[j]+1);
                }
            }
        }
        return countV[np];
    }
};