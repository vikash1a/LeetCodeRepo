class Solution {
public:

    int countPrimes(int n) {
        if(n<=1)return 0;
        int count = 0;
        vector<bool> seen(n,false);
        for(int i=2;i<n;i++){
            if(seen[i])continue;
            count++;
            for(long j=(long)i*i; j<n;j+=i){
                seen[j] = true;
            }
        }
        return count;
    }
};
/*
isPrime - sqrt(n)
2,3,5
O(n*sqrt)
*/