class Solution {
public:
    bool static compare(pair<int,string>  p1, pair<int,string> p2){
        if (p1.first == p2.first) return p1.second < p2.second;
        else return p1.first > p2.first;
    }
    void print(priority_queue<pair<int,string>, vector<pair<int,string>>, function<bool(pair<int,string>, pair<int,string>)>> pq){
        while(!pq.empty()){
            pair<int,string> p = pq.top();
            cout<<p.first<<" _ "<<p.second<<endl;
            pq.pop();
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int nw = words.size()-1;
        priority_queue<pair<int,string>, vector<pair<int,string>>, function<bool(pair<int,string>, pair<int,string>)>> pq(compare);
        unordered_map<string, int> unmp;
        for(string s: words){
            if(unmp.find(s)==unmp.end())unmp[s] = 1;
            else unmp[s]+=1;
        }
        for(auto it = unmp.begin(); it!=unmp.end(); it++){
            // cout<<it->first<<" - "<<it->second<<endl;
            if(pq.size()>k)pq.pop();
            pq.push({it->second, it->first});
            // print(pq);
            
        }
        vector<string> result;
        if(pq.size()>k)pq.pop();
        while(!pq.empty()){
            pair<int,string> p = pq.top();
            pq.pop();
            result.push_back(p.second);
        }
        reverse(result.begin(), result.end());
        // cout<<("aaa">"a")<<endl;
        return result;

    }
};