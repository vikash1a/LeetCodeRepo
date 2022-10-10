class Solution {
public:
    int helper(vector<string>& strs, int k, int m, int n,vector<vector<vector<int>>>& dp){
        if(k > strs.size()-1) return 0;
        if(dp[k][m][n]!=-1){
            return dp[k][m][n];
        }
        int m1=0;
        for(char c : strs[k])if(c=='0')m1+=1;
        int n1 = strs[k].size()-m1;
        
        int a = 0, b = 0;
        b = helper(strs,k+1,m,n,dp);
        if(m-m1>=0 && n-n1>=0 ){
            a = 1+helper(strs,k+1,m-m1,n-n1,dp);
        }
        
        // cout<<k<<" "<<m<<" "<<n<<" "<<a<<" "<<b<<endl;
        dp[k][m][n] = max(a,b);
        return max(a,b);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ns = strs.size()-1;
        vector<vector<vector<int>>> dp(ns+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs,0,m,n,dp);
    }

};