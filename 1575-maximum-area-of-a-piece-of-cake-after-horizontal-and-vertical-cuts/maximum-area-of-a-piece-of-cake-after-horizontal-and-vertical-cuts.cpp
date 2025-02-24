class Solution {
public:
    int mod = 1e9+7;
    int sol1(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts){
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxAreaValue = 1;
        for(int i=0;i<=(int)verticalCuts.size()-1+1;i++){
            int localArea = 1;
            int x1,x2;
            if(i==0)x1 = 0;
            else x1 = verticalCuts[i-1];
            if(i == verticalCuts.size()) x2 = w;
            else x2 = verticalCuts[i];
            for(int j=0;j<=(int)horizontalCuts.size()-1+1;j++){
                int y1, y2;
                if(j==0)y1 = 0;
                else y1 = horizontalCuts[j-1];
                if(j == horizontalCuts.size()) y2 = h;
                else y2 = horizontalCuts[j];

                int area = ((y2-y1)%mod)*((x2-x1)%mod);

                localArea = max(localArea, area);
            }
            maxAreaValue = max(maxAreaValue, localArea);
        }
        return maxAreaValue;
    }
    int sol2(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long maxHeight = 1;
        int nh = (int)horizontalCuts.size()-1;
        for(int i=0;i<=nh+1;i++){
            long height;
            if(i==0)height = horizontalCuts[0];
            else if(i==nh+1)height = h-horizontalCuts[nh];
            else height = horizontalCuts[i]-horizontalCuts[i-1];
            maxHeight = max(maxHeight, height);
            // cout<<i<<" "<<height<<"-"<<maxHeight<<endl;
        }
        long maxWidth = 1;
        int nv = (int)verticalCuts.size()-1;
        for(int i=0;i<=nv+1;i++){
            long width;
            if(i==0)width = verticalCuts[0];
            else if(i==nv+1)width = w-verticalCuts[nv];
            else width = verticalCuts[i]-verticalCuts[i-1];
            maxWidth = max(maxWidth, width);
        }
        // cout<<maxWidth<<" "<<maxWidth<<endl;
        return (((maxHeight)%mod)*((maxWidth)%mod))%mod;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return sol2(h,w,horizontalCuts,verticalCuts);
    }
};
/*
Brute Force - O(n*n)

*/