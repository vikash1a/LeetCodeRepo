#define usl  unsigned long long 
class Solution {
public:
    long long mod = 1e9+7;
    
    int concatenatedBinary(int n) {
        usl totalDecimalValue = 0;
        usl i = 1;
        while(i<=n){
            usl nBit = log2(i)+1;
            totalDecimalValue  = ((totalDecimalValue<<nBit)%mod +i)%mod;
            i++;
        }
        return totalDecimalValue;
    }
};
/*


*/