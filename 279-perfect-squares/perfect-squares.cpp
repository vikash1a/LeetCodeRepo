class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n+1, INT_MAX);
        for(int i=1;i<=sqrt(n);i++){
            v[i*i] = 1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                if(v[i]==1)break;
                v[i] = min(v[i],v[j]+v[i-j]);
            }
        }
        return v[n];
    }
};