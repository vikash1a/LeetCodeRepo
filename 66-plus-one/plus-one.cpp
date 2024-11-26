class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 0;
        for(int i=0;i<=digits.size()-1;i++){
            int diModifeid = 0;
            int di = digits[digits.size()-1-i];
            if(i==0){
                carry = (di+1)/10;
                diModifeid = (di+1)%10;
            }
            else {
                
                diModifeid = (di+carry)%10;
                carry = (di+carry)/10;
            }
            // cout<<diModifeid<<" "<<carry<<endl;
            result.push_back(diModifeid);
        }
        if(carry>=1)result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};