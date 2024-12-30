class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int mutatedCount = 0;
        for(int i=0;i<=num.size()-1;i++){
            // cout<<i<<" "<<mutatedCount<<endl;
            if(num[i]-'0'==change[num[i]-'0'])continue;
            else if(num[i]-'0'<change[num[i]-'0']){
                if(mutatedCount!=-1){
                    num[i] = change[num[i]-'0']+'0';
                    mutatedCount++;
                }
            }else{
                if(mutatedCount>=1)mutatedCount = -1;
            }
        }
        return num;
    }
};