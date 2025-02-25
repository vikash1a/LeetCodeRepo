class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int no = (int)orders.size()-1;
        set<string> foodItems;
        set<int> tables;
        for(vector<string> v: orders){
            foodItems.insert(v[2]);
            tables.insert(stoi(v[1]));
        }
        int nf = foodItems.size()-1, nt = tables.size()-1;
        vector<vector<string>> result(nt+2, vector<string>(nf+2,"0"));
        result[0][0] = "Table";
        int i = 1;
        for(auto it : foodItems){
            result[0][i] = it; i++;
        }
        i = 1;
        for(auto it : tables){
            result[i][0] = to_string(it); i++;
        }
        for(vector<string> v: orders){
            int r = distance(tables.begin(),tables.find(stoi(v[1])))+1;
            int c = distance(foodItems.begin(),foodItems.find(v[2]))+1;
            // cout<<result[r][c]<<endl;
            int currentValue = stoi(result[r][c]);
            result[r][c] = to_string(currentValue+1);
        }
        return result;
    }
};