class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> charV(26,0);
        for(char c: s)charV[c-'a']+=1;
        int oddCount = 0, evnePairCount = 0;
        for(int i=0; i<=25; i++){
            int k1 = charV[i];
            // if(k1>0)cout<<i<<" "<<k1<<endl;
            if(k1%2==1)oddCount+=1;
            evnePairCount+=k1/2;
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
maxvalue - no of odd chars + no of even pair

*/