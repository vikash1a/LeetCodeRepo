class Solution {
public:
    bool isDivisibleBy5(string& s,int is, int ie ){
        long long num = 0;
        for(int i = is;i<=ie;i++){
            num+= (s[i]-'0')*((long long)(pow(2,ie-i)));
        }
        if(num==1)return true;
        while(num>1){
            if(num%5!=0)return false;
            num/=5;
        }
        return true;
    }
    int util(string &s, int is, int ie, vector<vector<int>>& dp ){
        // cout<<is<<" "<<ie<<endl;
        if(dp[is][ie]!=INT_MAX)return dp[is][ie];
        int minValue = INT_MAX;
        if(s[is]=='0')minValue = -1;
        else if(s[is]=='1' && (is==ie))minValue = 1;
        else if(isDivisibleBy5(s, is, ie))minValue =  1;
        else{
            for(int i=is;i<=ie-1;i++){
                int m1 = util(s,is,i,dp);
                int m2 = util(s,i+1,ie,dp);
                // cout<<s1<<"="<<m1<<"  "<<s2<<"="<<m2<<endl;
                if(m1!=-1 && m2!=-1)minValue = min(minValue, m1+m2);
            }
        }
        if(minValue == INT_MAX)minValue = -1;
        dp[is][ie] = minValue;
        // cout<<s.substr(is,ie-is+1)<<" "<<minValue<<endl;
        return minValue;
    }
    int minimumBeautifulSubstrings(string s) {
        int ns = s.size()-1;
        vector<vector<int>> dp (ns+1, vector<int>(ns+1,INT_MAX));
        return util(s,0,ns, dp);
    }
};
/*



5 101
10 0101
15 1111
20 00101
25 10011
30 01111
35 110001
40 000101
*/