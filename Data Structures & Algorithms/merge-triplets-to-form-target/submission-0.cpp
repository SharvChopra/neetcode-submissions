class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
         //Brute Force
        for(int i=0;i<triplets.size();i++){
            vector<int>temp(3,0);
            for(int j=0;j<triplets.size();j++){
                if(i==j){
                    continue;
                }
                else{
                    temp[0] = max(triplets[i][0],triplets[j][0]);
                    temp[1] = max(triplets[i][1],triplets[j][1]);
                    temp[2] = max(triplets[i][2],triplets[j][2]);
                }
            }
            for(int i=0;i<3;i++){
                if(temp[i] != target[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
