class Solution {
public:
    // vector<string> split(string s,string delim){
    //     vector<string> vs;
    //     int n = s.size()-1;
    //     int start =0, end = n;
    //     while(end!=-1){
    //         end = s.find(delim,start);
    //         if(end!=-1){
    //             vs.push_back(s.substr(start,end-start));
    //         }
    //         else{
    //             vs.push_back(s.substr(start,n));
    //             break;
    //         }
    //         start = end+delim.size();
    //     }
    //     return vs;
    // }
    vector<string> split(string s,string delim){
        vector<string> vs;
        int n = s.size()-1;
        vs.push_back("");
        int i=0;
        while(i<=n){
            if(s[i]!=' '){
                vs[vs.size()-1]+=s[i];
            }
            else{
                // cout<<i<<" "<<vs[vs.size()-1].size()<<" "<<vs.size()<<endl;
                if(vs[vs.size()-1].size()!=0)vs.push_back("");
            }
            i++;
        }
        if(vs[vs.size()-1].size()==0)vs.pop_back();
        return vs;
    }
    string reverseWords(string s) {
        vector<string> vs = split(s," ");
        reverse(vs.begin(),vs.end());
        s="";
        for(string s1: vs){
            // cout<<"-"<<s1<<"-"<<endl;
            s+=s1+" ";
        }
        s.pop_back();
        return s;
    }
};