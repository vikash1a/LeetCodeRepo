class Solution {
public:
    string repeat(string s, int times){
        string repeatedString;
        while(times--)repeatedString+=s;
        return repeatedString;
    }
    bool isDigit(char c){
        return c-'0'>=0 && c-'0'<=9;
    }
    string decodeString(string s) {
        string decodedString="";
        int ns = (int)s.size()-1;
        if(ns<=0)return s;
        int i=0;
        while(i<=ns){
            if(isDigit(s[i])){
                int j=i;
                while(i<=ns && isDigit(s[i])){
                    i++;
                }
                int times = stoi(s.substr(j,i-j));
                i+=1;
                string ss="";
                int sum = 0;
                while(i<=ns){
                    if(s[i] == '[')sum+=1;
                    if(s[i] == ']'){
                        if(sum == 0)break;
                        sum-=1;
                    }
                    ss+=s[i];
                    i++;
                }
                // cout<<i<<"-"<<ss<<"-"<<times<<endl;
                decodedString+=repeat(decodeString(ss),times);
            }
            else decodedString+=s[i];
            i++;
        }
        // cout<<s<<"_"<<decodedString<<endl;
        return decodedString;
    }
};