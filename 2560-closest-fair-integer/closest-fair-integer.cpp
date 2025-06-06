class Solution {
public:
    vector<int> digitToVector(int n){
        vector<int> result;
        while(n>0){
            result.push_back(n%10);
            n/=10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int vectorToDigit(vector<int> result){
        int n = 0;
        for(int i=0;i<=result.size()-1;i++){
            n+=result[i]*pow(10,result.size()-1-i);
        }
        return n;
    }
    int getNextMax(int nv){
        if(nv==1)return 10;
        vector<int> nextMax = vector<int>(nv+1,0);
        nextMax[0] = 1, nextMax[nv] = 1;
        int i=nv-1, count = (nv+1)/2-2;
        while(count--){
            nextMax[i] = 1;
            i--;
        }
        return vectorToDigit(nextMax); 
    }
    int closestFair(int n) {
        vector<int> v = digitToVector(n);
        int nv = v.size();
        if(nv%2!=0)return getNextMax(nv);
        else{
            int ec = 0;
            for(int k: v){
                // cout<<k<<"-";
                if(k%2 ==0)ec++;
            }
            if(ec == nv/2)return vectorToDigit(v);
            if(ec < nv/2){
                int evenUpdate = nv/2-ec;
                for(int i=nv-1;i>=0;i--){
                    if(v[i]%2 == 0)v[i] = 0;
                    else{
                        if(evenUpdate >= 2)v[i] = 0;
                        else v[i]+=1;
                        evenUpdate--;
                    }
                    if(evenUpdate == 0)break;
                }
            }
            else{
                int oddUpdate = abs(nv/2-ec);
                for(int i=nv-1;i>=0;i--){
                    if(v[i]%2 != 0)v[i] = 1;
                    else{
                        if(oddUpdate >= 2)v[i] = 1;
                        else v[i]+=1;
                        oddUpdate--;
                    }
                    if(oddUpdate == 0)break;
                }
            }
        }
        // for(int k: v)cout<<k<<"-";
        int carry = 0;
        for(int i=nv-1;i>=0;i--){
            if(v[i]>=10){
                v[i]%=10;
                carry = 1;
            }
            else{
                if(carry == 1){
                    v[i]+=2;
                    if(v[i]>=10){
                        v[i]%=10;
                        carry = 1;
                    }
                    else carry = 0;
                }
            }

        }
        if(carry>=1)return getNextMax(nv+1);
        return vectorToDigit(v);
    }
};