class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())return false;
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        set<char> s1;
        set<char> s2;
        for(char c: word1){v1[c-'a']+=1;s1.insert(c);}
        for(char c: word2){v2[c-'a']+=1;s2.insert(c);}
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return s1==s2 && v1==v2;
    }
};