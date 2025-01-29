class Solution {
public:
    int minChanges(string s) {
        int changeCount = 0;
        for(int i=0;i<=s.size()-1;i+=2){
            if(s[i]!=s[i+1]) changeCount+=1;
        }
        return changeCount;
    }
};
/*
2,4,6,8
*/