class Solution {
public:
    vector<int> getNum(stack<string>& st){
        string s1 = st.top();
        st.pop();
        string s2 = st.top();
        st.pop();
        return {stoi(s2),stoi(s1)};
    }
    int evalRPN(vector<string>& tokens) {
        int nt = tokens.size()-1;
        stack<string> st;
        vector<int> v;
        for(int i=0; i<=nt; i++){
            string s = tokens[i];
            // cout<<s<<" "<<result<<endl;
            if(s == "+"){
                v = getNum(st);
                st.push(to_string(v[0] + v[1]));
            }
            else if(s == "-"){
                v = getNum(st);
                st.push(to_string(v[0] - v[1]));
            }
            else if(s == "*"){
                v = getNum(st);
                st.push(to_string(v[0] * v[1]));
            }
            else if(s == "/"){
                v = getNum(st);
                st.push(to_string(v[0] / v[1]));
            }
            else{
                st.push(s);
            }
        }
        return stoi(st.top());
    }
};