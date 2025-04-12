class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> charV(26,0);
        for(char c: s)charV[c-'a']+=1;
        int oddCount = 0;
        for(int k1: charV){
            if(k1%2==1)oddCount+=1;
        }
        return (k>=oddCount && k<=s.size());
    }
};
/*
a,b,c

e-3,l-1,t-1,c-1,o-1
a-2,n-2,b-1,e-2,l-2

one odd + any number of even
no of odd -> at least that number of palindrome can be created, less - no, more - yes, how many more? - no of even pair
minValue - no of odd chars
maxvalue - no of char in s

*/