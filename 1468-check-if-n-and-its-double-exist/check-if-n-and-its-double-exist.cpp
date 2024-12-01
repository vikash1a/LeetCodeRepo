class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> ust;
        for(int k: arr){
            if(
                abs(k)!=1 && 
            ((abs(k)%2==0 && ust.find(k/2)!=ust.end()) || 
            (ust.find(k*2)!=ust.end())))return true;
            ust.insert(k);
        }
        return false;
    }
};