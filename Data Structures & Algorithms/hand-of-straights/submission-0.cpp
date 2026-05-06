class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0){
            return false;
        }
        map<int,int>mp; //already sorted map
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }

        while(!mp.empty()){
            int idx = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[idx+i] == 0){
                    return false;
                }
                mp[idx+i]--;
                if(mp[idx+i] == 0){
                    mp.erase(idx+i);
                }
            }
        }
        return true;
    }
};
