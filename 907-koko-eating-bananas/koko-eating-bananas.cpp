class Solution {
public:
    long long getTime(vector<int>& piles, long long speed){
        long long time = 0;
        for(int k: piles){
            time += k/speed;
            if(k%speed!=0)time++;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int np = (int)piles.size()-1;
        long long s = 1, e = *max_element(piles.begin(), piles.end());
        long long minSpeed = e;
        while(s<=e){
            long long m = s+(e-s)/2;
            long long sv = getTime(piles, s);
            long long ev = getTime(piles, e);
            long long mv = getTime(piles, m);
            // cout<<s<<" "<<m<<" "<<e<<endl;
            // cout<<sv<<"-"<<mv<<"-"<<ev<<endl;
            if(mv<=h){
                minSpeed = m;
                e = m-1;
            }
            else {
                s = m+1;
            }
        }
        return minSpeed;
    }
};
/*
Bruteforce - O(N)*O(N)


*/