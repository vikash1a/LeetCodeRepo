class Solution {
public:
    int mod = 1e9+7;
    int maxV = 1e5+2;
    vector<long long> count;
    void prepare(){
        count.resize(maxV);
        count[0] = 0;count[1] = 1;
        for(int i=2;i<=maxV-1;i++){
            count[i] = (count[i-1]+i-1+1)%mod;
        }
    }
    int numSub(string s) {
        prepare();
        int ns = s.size()-1;
        int tempCount = 0;
        int totalCount = 0;
        for(int i=0;i<=ns;i++){
            if(s[i]=='1')tempCount+=1;
            else{
                totalCount = (totalCount+count[tempCount])%mod;
                tempCount = 0;
            }
        }
        totalCount = (totalCount+count[tempCount])%mod;
        return totalCount;
    }
};

/*
1-> 1 
2-> 2(1)+1(2)-> 3
3 -> 3(1)+2(2)+1(3) -> 3 + 2 +1
4 -> 4(1)+3(2)+2(3)+1(4) -> 6 + 3 + 1
5-> 9
*/