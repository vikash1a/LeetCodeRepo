class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v = {1};
        while(rowIndex--){
            vector<int> temp = v;
            v.clear();
            v.push_back(1);
            for(int i=0;i<=(int)temp.size()-2;i++){
                v.push_back(temp[i]+temp[i+1]);
            }
            v.push_back(1);
        }
        return v;
    }
};