class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        long expectedCount = pow(2,k);
        for(int i=0;i+k-1<=s.size()-1;i++){
            string ss = s.substr(i,k);
            st.insert(ss);
        }
        
        
        return st.size()==expectedCount;
    }
};
/*
1 - 0,1
2 - 00,01,10,11
3 - 000,001,010,011

Bf - O(n)*O(2^k)

Optimised -> O(n)*O(k)
check all k length subarray -> O(n)
add in vector of O(k) 
check count of k at end

*/