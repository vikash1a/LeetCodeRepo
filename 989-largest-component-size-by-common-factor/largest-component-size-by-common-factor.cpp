class DisjointSet{
    unordered_map<int, int> rank;
    unordered_map<int, int> parent;
    public:
        int find(int u){
            if(parent.find(u) == parent.end()){
                parent[u] = u;
                rank[u] = 0;
                return u;
            }
            if(u!=parent[u]){
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }
        void unionPair(int u, int v){
            int pu = find(u);
            int pv = find(v);
            if(pu>pv){
                parent[pv] = pu;
            }
            else if(pu<pv){
                parent[pu] = pv;
            }
            else {
                rank[pu]+=1;
                parent[pv] = pu;
            }
            return;
        }
        bool isConnected(int u, int v){
            return find(u)==find(v);
        }
};

class Solution {
public:
    vector<int> primeDecompose(int num){
        vector<int> v;
        int factor = 2;
        while(num>=factor*factor){
            if(num%factor == 0){
                num/=factor;
                v.push_back(factor);
            }
            else factor+=1;
        }
        v.push_back(num);
        return v;
    }
    int largestComponentSize(vector<int>& nums) {
        int nn = nums.size()-1;
        DisjointSet ds = DisjointSet();
        unordered_map<int,int> unmp;
        for(int i=0;i<=nn;i++){
            vector<int> pv = primeDecompose(nums[i]);
            unmp[nums[i]] = pv[0];
            for(int j=0;j<=(int)pv.size()-2;j++){
                ds.unionPair(pv[j], pv[j+1]);
            }
        }
        int largestComponent = 0;
        unordered_map<int,int> unmpCount;
        for(int i=0;i<=nn;i++){
            int p = ds.find(unmp[nums[i]]);
            // cout<<nums[i]<<" "<<p<<endl;
            if(unmpCount.find(p) == unmpCount.end())unmpCount[p] = 1;
            else unmpCount[p]+=1;
            largestComponent = max(largestComponent, unmpCount[p]);
        }
        return largestComponent;
    }
};
/*
check for each combination - O(n^2)

*/