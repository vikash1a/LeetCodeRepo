class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        priority_queue<int> pq;
        int ni = (int)items.size()-1, nq = (int)queries.size()-1;
        sort(items.begin(), items.end());
        vector<pair<int,int>> queriesP(nq+1);
        for(int i=0;i<=nq;i++){
            queriesP[i] = {queries[i],i};
        }
        sort(queriesP.begin(), queriesP.end());
        int ii = 0;
        vector<int> answers(nq+1,0);
        for(int i=0;i<=nq;i++){
            while(ii<=ni && items[ii][0]<=queriesP[i].first ){
                pq.push(items[ii][1]);
                ii++;
            }
            if(!pq.empty())answers[queriesP[i].second] = pq.top();
            // cout<<i<<" "<<ii<<endl;
        }
        return answers;
    }
};
/*
Brute force - O(q)*O(n)

*/