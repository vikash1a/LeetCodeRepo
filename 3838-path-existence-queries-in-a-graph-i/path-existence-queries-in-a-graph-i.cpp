class DisjointSet{
    private:
        vector<int> rank;
        vector<int> parent;
        int find(int x){
            if(x!=parent[x]){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
    public:
        
        DisjointSet(int n){
            rank.resize(n);
            parent.resize(n);
            for(int i=0;i<=n-1;i++){
                rank[i] = 0;parent[i] = i;
            }
        }
        
        void union1(int u, int v){
            int pu = find(u);
            int pv = find(v);
            if(rank[pu] < rank[pv]){
                parent[u] = pv;
            }
            else if(rank[pu] > rank[pv]){
                parent[v] = pu;
            }
            else{
                parent[v] = pu;
                rank[pu]+=1;
            }
            return;
        }
        bool isConnected(int u, int v){
            return find(u) == find(v);
        }
        void print(){
            for(int r: rank){
                cout<<r<<" ";
            }cout<<endl;
            for(int p: parent){
                cout<<p<<" ";
            }cout<<endl;
        }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> result(queries.size(), false);
        DisjointSet ds = DisjointSet(n);
        for(int i=0;i<=n-2;i++){
            if(nums[i+1]-nums[i]<=maxDiff)ds.union1(i,i+1);
        }
        // ds.print();
        for(int i=0;i<=queries.size()-1; i++){
            int u = queries[i][0], v = queries[i][1];
            // bool isPath = (abs(nums[u]-nums[v]) <= maxDiff);
            // cout<<"debg1"<<endl;
            // if(isPath)ds.union1(u,v);
            result[i] = ds.isConnected(u,v);
            // cout<<u<<" "<<v<<" "<<" "<<result[i]<<endl;
        }
        return result;
    }
};
/*
1 2


*/