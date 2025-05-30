class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        unordered_set<int> ust;
        for(int i=0;i<=edges.size()-1;i++){
            ust.insert(edges[i][1]);
        }
        for(int i=0;i<=n-1;i++){
            if(ust.find(i)==ust.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};
/*
- convert to adj list
- first start dfs with 
*/