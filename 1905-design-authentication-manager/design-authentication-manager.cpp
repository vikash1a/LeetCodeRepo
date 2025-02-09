class AuthenticationManager {
public:
    int timeToLive = 0;
    unordered_map<string, int> unmp;
    AuthenticationManager(int _timeToLive) {
        timeToLive = _timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        unmp[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if(unmp.find(tokenId) == unmp.end())return;
        if(unmp[tokenId]>currentTime){
            unmp[tokenId] = currentTime + timeToLive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto it = unmp.begin(); it != unmp.end(); it++){
            if(it->second > currentTime)count+=1;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */