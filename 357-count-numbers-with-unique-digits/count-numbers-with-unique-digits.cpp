class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        int count = 1;
        for(int i=0;i<=n-1;i++){
            if(i<=1)count*=(9);
            else count*=(9-i+1);
        }
        return count+countNumbersWithUniqueDigits(n-1);
        
    }
};
/*
0 - 1
1 - 10
2 - 90
3 - 721

*/
