class Solution {
public:
    vector<int> v1 = vector<int>(1001,-1);
    vector<int> v2 = vector<int>(1001,-1);
    int mod = 1e9+7;
    int partialTilling(int n){
        if(v2[n]!=-1)return v2[n];
        if(n<=2)return 1;
        int num = 0;
        // hor
        num+=partialTilling(n-1);
        num%=mod;

        // tri
        num+=numTilings(n-2);
        num%=mod;
        v2[n] = num;
        return num;
    }
    int numTilings(int n) {
        if(v1[n]!=-1)return v1[n];
        if(n<=2)return n; 
        int num = 0;
        // fill first vertical column
        num += numTilings(n-1);
        num%=mod;
        // fill first two vertical column
        num += numTilings(n-2);
        num%=mod;
        // fill first 3 vertical column
        num += (2*partialTilling(n-1))%mod;;
        num%=mod;
        // cout<<n<<" "<<num<<endl;
        v1[n] = num;
        return num;
    }
};
/*
1 - 1
2 - 

*/