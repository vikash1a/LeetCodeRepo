class Solution {
public:
    string sortSpecial(string s){
        string s1 = "", s2 = "";
        for(int i=0;i<=s.size()-1;i++){
            if(i%2==0)s2+=s[i];
            else s1+=s[i];
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        string sModified = "";
        int i1 = 0, i2 = 0;
        for(int i=0;i<=s.size()-1;i++){
            if(i%2==0){
                sModified += s2[i2];
                i2++;
            }
            else {
                sModified += s1[i1];
                i1++;
            }
        }
        return sModified;
    }
    int numSpecialEquivGroups(vector<string>& words) {
        int nw = words.size()-1;
        int count = 0;
        for(int i=0;i<=nw;i++){
            words[i] = sortSpecial(words[i]);
        }
        sort(words.begin(), words.end());
        string lastWord = "";
        for(int i=0;i<=nw;i++){
            if(words[i] == lastWord)continue;
            else{
                count++;
                lastWord = words[i];
            }
        }
        return count;
    }
};