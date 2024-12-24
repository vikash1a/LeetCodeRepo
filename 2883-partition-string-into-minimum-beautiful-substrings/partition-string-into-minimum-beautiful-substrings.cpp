class Solution {
public:

    unordered_map<string,int> unmp;
    bool isDivisibleBy5(string& s){
        long long num = 0;
        for(int i = 0;i<=(int)s.size()-1;i++){
            num+= (s[i]-'0')*((long long)(pow(2,(int)s.size()-1-i)));
        }
        if(num==1)return true;
        while(num>1){
            if(num%5!=0)return false;
            num/=5;
        }
        return true;
    }
    int minimumBeautifulSubstrings(string s) {
        if(unmp.find(s)!=unmp.end())return unmp[s];
        int minValue = INT_MAX;
        if(s[0]=='0')minValue = -1;
        else if(s=="1")minValue = 1;
        else if(isDivisibleBy5(s))minValue =  1;
        else{
            int ns = s.size()-1;
            for(int i=1;i<=ns;i++){
                int m1 = minimumBeautifulSubstrings(s.substr(0,i));
                int m2 = minimumBeautifulSubstrings(s.substr(i, ns+1));
                // cout<<s1<<"="<<m1<<"  "<<s2<<"="<<m2<<endl;
                if(m1!=-1 && m2!=-1)minValue = min(minValue, m1+m2);
            }
        }
        if(minValue == INT_MAX)minValue = -1;
        unmp[s] = minValue;
        // cout<<s<<" "<<minValue<<endl;
        return minValue;
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