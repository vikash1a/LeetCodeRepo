class Solution {
public:
    int getReverse(int k){
        int result = 0;
        for(;k>0;k/=10){
            result = result*10+k%10;
        }
        return result;
    }
    bool sumOfNumberAndReverse(int num) {
        bool result = false;
        for(int i=num/2;i<=num;i++){
            int reverse = getReverse(i);
            if(num == i+reverse)return true;
        }
        return result;
    }
};
/*
Bruteforce - O(n)
2 -> 0,2 1,1 3,9 4,8 5,7 6,6  -> i,(2-i)%10
*/