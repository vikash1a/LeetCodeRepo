class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())return "0";
        string ans = "";
        stack<char> st;
        for(char c : num){
            if(k==0){
                st.push(c);
                continue;
            }
            if(st.empty())st.push(c);
            else{
                if(c>=st.top()){
                    st.push(c);
                }
                else{
                    while(!st.empty() && st.top()>c && k>0){
                        st.pop();
                        k--;
                    }
                    st.push(c);
                }
            }
        }
        while(k--){
            st.pop();
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int countLeadingZero = 0;
        for(char c: ans){
            if(c!='0')break;
            countLeadingZero++;
        }
        ans = ans.substr(countLeadingZero,ans.size());
        if(ans=="")return "0";
        return ans;
    }
};

/*
1432219

10200
11200

10
14

44200
4321

12
21

234

432
*/