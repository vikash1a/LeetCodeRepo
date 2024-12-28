class Solution {
public:
    double getTime(vector<int>& dist, int v){
        double time = 0;
        for(int i=0;i<=dist.size()-1;i++){
            double t = (double)dist[i]/(double)v;
            if(i==dist.size()-1)time+=t;
            else time+=ceil(t);
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size()>ceil(hour))return -1;
        int s=1, e = INT_MAX;
        int minSpeed = INT_MAX;
        while(s<=e){
            int m = s+(e-s)/2;
            double sv = getTime(dist, s);
            double ev = getTime(dist, e);
            double mv = getTime(dist, m);

            // cout<<s<<" "<<m<<" "<<e<<" "<<sv<<" "<<mv<<" "<<ev<<endl;

            if(mv<=hour){
                e = m-1;
                minSpeed = min(minSpeed, m);
            }
            else {
                s = m+1;
            }
            
            
        }
        return minSpeed;
    }
};
/*
""
*/