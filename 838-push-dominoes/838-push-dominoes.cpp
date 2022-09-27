class Solution {
public:
    string pushDominoes(string dominoes) {
        int nd = dominoes.size()-1;
        int i = 0;
        int lastValue = 0;
        while(i<=nd){
             // cout<<i<<"-"<<lastValue<<endl;
            if(dominoes[i] == 'L'){
                if(dominoes[lastValue] == 'R'){
                    int lowerHalf = lastValue+(i-lastValue+1)/2-1;
                    int upperHalf = i-((i-lastValue+1)/2-1);
                    // cout<<i<<" "<<lowerHalf<<" "<<upperHalf<<" "<<lastValue<<endl;
                    while(lowerHalf>=lastValue){
                        dominoes[lowerHalf] = 'R';
                        lowerHalf--;
                    }
                    while(upperHalf<=i){
                        dominoes[upperHalf] = 'L';
                        upperHalf++;
                    }
                }
                else{
                    while(lastValue<=i){
                        dominoes[lastValue] = 'L';
                        lastValue++;
                    }
                }
                lastValue = i;
            }
            else if(dominoes[i] == 'R'){
                if(dominoes[lastValue] == 'R' ){
                    while(lastValue<=i){
                        dominoes[lastValue] = 'R';
                        lastValue++;
                    }
                }
                 lastValue = i;
            }
            else if(i==nd && dominoes[lastValue] == 'R'){
                while(lastValue<=i){
                    dominoes[lastValue] = 'R';
                    lastValue++;
                }
            }
            i++;
        }
        return dominoes;
    }
};