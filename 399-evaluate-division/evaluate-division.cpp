
class Solution {
public:
    double getValue(unordered_map<string, vector<pair<string,double>>>& unmp, string s, string d, unordered_set<string> ust){
        // cout<<s<<" "<<d<<endl;
        if(s==d) return 1.0;
        if(unmp.find(s)==unmp.end())return -1.0;

        for(int i=0;i<=(int)unmp[s].size()-1;i++){
            if(ust.find(unmp[s][i].first)!=ust.end())continue;
            ust.insert(unmp[s][i].first);
            double localResult = getValue(unmp, unmp[s][i].first, d, ust);
            if(localResult!=-1){
                return (unmp[s][i].second)*localResult;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int ne = equations.size()-1;
        unordered_map<string, vector<pair<string,double>>> unmp;
        for(int i=0;i<=ne;i++){
            unmp[equations[i][0]].push_back({equations[i][1], values[i]});
            unmp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        int nq = queries.size()-1;
        vector<double> queryResult(nq+1);
        for(int i=0;i<=nq;i++){
            unordered_set<string> ust;
            ust.insert(queries[i][0]);
            double result = -1.0;
            if(unmp.find(queries[i][0])==unmp.end() || unmp.find(queries[i][1])==unmp.end()){
                result = -1.0;
            }
            else if(queries[i][0] == queries[i][1]) result = 1.0;
            else result = getValue(unmp,queries[i][0],queries[i][1],ust);
            queryResult[i] = result;
        }
        return queryResult;
    }
};
/*
a/b b/c
a(2)->b(3)->c

a/c b/a a/e a/a x/x

a->(1.5)b->(2.5)c
        b->(5)d

can be represented in a graph
find if we can travel from node a to b 

standard - find distance between two nodes in a directed graph
a->b
c->b
a/b c/b -
*/