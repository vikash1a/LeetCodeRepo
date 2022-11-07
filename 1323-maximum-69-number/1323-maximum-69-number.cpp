class Solution {
public:
    vector<int> numToVec(int k){
        vector<int> v;
        while(k>0){
            v.push_back(k%10);
            k/=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
    int vecToNum(vector<int> v){
        int k = 0;
        for(int i=0;i<=v.size()-1;i++){
            k+=v[i]*pow(10,v.size()-1-i);
        }
        return k;
    }
    int maximum69Number (int num) {
        vector<int> v = numToVec(num);
        for(int i=0;i<=v.size()-1;i++){
            if(v[i]==6){
                v[i] = 9;break;
            }
        }
        return vecToNum(v);
    }
    
};