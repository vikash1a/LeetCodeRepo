class Solution {
public:
    void helper(string digits,vector<string>& ans,string temp,unordered_map<char,string>& unmp){
        if(digits.size()==0){
            if(temp.size()>=1)ans.push_back(temp);
            return;
        }
        string keyValues = unmp[digits[0]];
        for(char c : keyValues){
            temp+=c;
            helper(digits.substr(1,digits.size()),ans,temp,unmp);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        // if(digits.size()==0)return {""};
        vector<string> ans;
        unordered_map<char,string> unmp;
        unmp['2'] = "abc"; unmp['3'] = "def"; unmp['4'] = "ghi"; unmp['5'] = "jkl";
        unmp['6'] = "mno";unmp['7'] = "pqrs"; unmp['8'] = "tuv"; unmp['9'] = "wxyz"; 
        
        helper(digits,ans,"",unmp);
        
        return ans;
    }
};