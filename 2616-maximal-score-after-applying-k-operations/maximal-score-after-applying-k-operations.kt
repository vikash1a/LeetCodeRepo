import kotlin.math.ceil

class Solution {
    /*
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
     */
    fun maxKelements(nums: IntArray, k: Int): Long {
        var maxScore: Long = 0
        // Max-heap: reverse order comparator
        val pq = PriorityQueue<Int>(compareByDescending { it })
        
        for (j in nums) {
            pq.add(j)
        }
        
        repeat(k) {
            val top = pq.poll()
            maxScore += top
            pq.add(ceil(top.toDouble() / 3).toInt())
        }
        
        return maxScore
    }
}