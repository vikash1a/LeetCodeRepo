class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long maxScore = 0;
        priority_queue<int> pq;
        for(int j: nums)pq.push(j);
        while(k--){
            int top = pq.top();
            pq.pop();
            maxScore += top;
            int topModified = top/3;
            if(top%3!=0)topModified+=1;
            pq.push(topModified);
            // cout<<top<<" "<<topModified<<endl;
        }
        return maxScore;
    }
};
/*


*/