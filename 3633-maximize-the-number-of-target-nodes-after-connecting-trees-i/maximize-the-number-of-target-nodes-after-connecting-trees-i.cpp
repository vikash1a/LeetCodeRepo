class Solution {
public:
    int maxElement(vector<vector<int>>& edges1){
        int maxE = INT_MIN;
        for(vector<int> v: edges1){
            for(int k: v)maxE = max(maxE, k);
        }
        return maxE;
    }
    void convertToAdj(vector<vector<int>>& edges1, vector<vector<int>>& adj1){
        for(vector<int> v: edges1){
            adj1[v[0]].push_back(v[1]);
            adj1[v[1]].push_back(v[0]);
        }
    }
    int getTotalTarget(vector<vector<int>>& adj1, int i, int k, vector<bool>& visited){
        visited[i] = true;
        if(k<0) return 0;
        if(k==0)return 1;
        int sum = 1;
        // sum+=adj1[i].size();
        for(int j=0;j<=(int)adj1[i].size()-1;j++){
            if(!visited[adj1[i][j]])sum+=getTotalTarget(adj1,adj1[i][j],k-1, visited);
            
        }
        // cout<<i<<" "<<k<<" "<<sum<<endl;
        return sum;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {             
        int ne1 = edges1.size()-1, ne2 = edges2.size()-1;
        int maxVertex1 =maxElement(edges1);
        int maxVertex2 =maxElement(edges2);           
        vector<int> maxTargets(maxVertex1+1);
        vector<vector<int>> adj1(maxVertex1+1);
        vector<vector<int>> adj2(maxVertex2+1);
        convertToAdj(edges1, adj1);
        convertToAdj(edges2, adj2);
       
        int maxTargetV2 = 0;
        for(int i=0;i<=maxVertex2;i++){
            vector<bool> visited2(maxVertex2+1, false);
            maxTargetV2 = max(maxTargetV2, getTotalTarget(adj2, i, k-1, visited2));
        }
        
        for(int i=0;i<=maxVertex1;i++){
            // cout<<i<<" "<<totalTarget1V[i]<<" "<<maxTargetV2<<endl;
            vector<bool> visited1(maxVertex1+1, false);
            maxTargets[i] = getTotalTarget(adj1, i, k, visited1)+(maxTargetV2);
        }
        return maxTargets;
    }
/*
Bruteforce - O(V*V), sc - O(V)
*/
};