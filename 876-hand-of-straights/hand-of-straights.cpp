class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int nh = hand.size()-1;
        if((nh+1)%groupSize !=0)return false;
        sort(hand.begin(), hand.end());
        int groupCount = 0;
        for(int i=0;i<=nh;i++){
            int count = 0;
            int prev = -1;
            for(int j=0;j<=nh;j++){
                if(hand[j]!=-1){
                    if(count == 0){
                        count+=1; prev = hand[j]; hand[j]=-1;
                    }
                    else{
                        if(hand[j] == prev)continue;
                        if(hand[j] == prev+1){
                            count+=1; prev = hand[j]; hand[j]=-1;
                        }
                        else return false;
                    }
                }
                // cout<<i<<" "<<j<<" "<<prev<<" "<<count<<endl;
                if(count == groupSize){groupCount+=1;break;}
            }
        }
        return groupCount==(nh+1)/groupSize;
    }
};
/*
1,2,2,3,3,4,6,7,8

*/