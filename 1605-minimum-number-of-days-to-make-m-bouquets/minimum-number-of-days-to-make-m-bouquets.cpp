class Solution {
public:
    int getBqCount(vector<int>& bloomDay, int& k, int& days){
        int bqCount = 0;
        int tempCount = 0;
        for(int i=0;i<=(int)bloomDay.size()-1;i++){
            if(bloomDay[i]<=days)tempCount++;
            else{
                bqCount += tempCount/k;
                tempCount = 0;
            }
        }
        bqCount += tempCount/k;
        return bqCount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s= *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int minDaysCount = INT_MAX;
        while(s<=e){
            int m1 = s+(e-s)/2;
            int sv = getBqCount(bloomDay, k, s);
            int ev = getBqCount(bloomDay, k, e);
            int m1v = getBqCount(bloomDay, k, m1);
            // cout<<s<<" "<<m1<<" "<<e<<endl;
            // cout<<sv<<"_"<<m1v<<"_"<<ev<<endl;
            if(m1v >= m){
                minDaysCount = min(minDaysCount, m1);
                e = m1-1;
            }
            else s = m1+1;
        }
        if(minDaysCount == INT_MAX)return -1;
        return minDaysCount;
    }
};
/*
Brute force - O(n^2)
use binary search
*/