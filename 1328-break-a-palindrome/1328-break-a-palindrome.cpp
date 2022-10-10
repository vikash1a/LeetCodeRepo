class Solution {
public:
    string breakPalindrome(string palindrome) {
        int ns = palindrome.size()-1;
        if(ns+1 == 1)return "";
        for(int i=0;i<=ns;i++){
            if((ns+1)%2==1 && i==(ns+1)/2)continue;
            if(palindrome[i]>'a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[ns]+=1;
        return palindrome;
    }
};