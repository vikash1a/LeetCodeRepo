class Solution {
public:
    string intMax= to_string(INT_MAX);
    bool isOutOfRange(string s){
        if(s.size()> intMax.size())return true;
        else if(s.size()< intMax.size())return false;
        else return s>intMax;
    }
    void util(string num, vector<int> fb, vector<int>& fbSeries){
        int nn = (int)num.size()-1;
        int nf = (int)fb.size()-1;
        if(nn+1<=0 && nf+1>=3){
            fbSeries = fb;
            return;
        }
        if(nf+1<=1){
            for(int i=0;i<=nn;i++){
                string ss = num.substr(0,i+1);
                if(ss[0]=='0' && ss.size()>=2)continue;
                if(isOutOfRange(ss))continue;
                int iv = stoi(ss);
                fb.push_back(iv);
                util(num.substr(i+1, nn), fb, fbSeries);
                fb.pop_back();
            }
        }
        else{
            long sum = (long)fb[nf]+(long)fb[nf-1];
            if(sum > INT_MAX)return;
            for(int i=0;i<=nn;i++){
                string ss = num.substr(0,i+1);
                if(ss[0]=='0' && ss.size()>=2)continue;
                if(isOutOfRange(ss))continue;
                int iv = stoi(ss);
                if(iv == sum){
                    fb.push_back(iv);
                    util(num.substr(i+1, nn), fb, fbSeries);
                    fb.pop_back();
                }
                
            }
        }
        // cout<<num<<endl;
        // for(int k: fb)cout<<k<<"_";
        // cout<<endl;
        // cout<<"- - - - - - "<<endl;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> fbSeries(0);
        util(num,{},fbSeries);
        return fbSeries;
    }
};
/*
brute force - 2^N
*/