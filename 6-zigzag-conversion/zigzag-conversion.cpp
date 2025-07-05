class Solution {
public:
    string convert(string s, int numRows) {
        int ns = s.size()-1;
        string result = "";
        vector<int> v;
        // row 1
        int i=0;
        while(i>=0 && i<=ns){
            char c = s[i];
            v.push_back(i);
            result+=c;
            int iOld = i;
            if(numRows == 1)i+=1;
            else i+=(2*(numRows-1));
            if(i==iOld)break;
        }

        // row rest
        for(int i=2;i<=numRows;i++){
            vector<int> vTemp(0);
            for(int j=0;j<=v.size()-1;j++){
                int aboveIndex = v[j];

                int firstIndex = aboveIndex+1;
                if(firstIndex > ns) break;
                vTemp.push_back(firstIndex);
                result+=s[firstIndex];

                if(i!=numRows){
                    int secondIndex = aboveIndex+ 1+((2*(numRows-i+1-1)));
                    if(secondIndex > ns) break;
                    // vTemp.push_back(secondIndex);
                    result+=s[secondIndex];
                }
                
            }
            // cout<<i<<" "<<result<<endl;
            v = vTemp;
        }
        return result;
    }
};
/*


*/