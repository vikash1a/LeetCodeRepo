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
            pq.push(ceil(((double)top)/3));
        }
        return maxScore;
    }
};
/*


*/