class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
         //Brute Force
        for(int i=0;i<triplets.size();i++){
            vector<int>temp = triplets[i];
            for(int j=0;j<triplets.size();j++){
                if(i==j){
                    continue;
                }
                    temp[0] = max(temp[0],triplets[j][0]);
                    temp[1] = max(temp[1],triplets[j][1]);
                    temp[2] = max(temp[2],triplets[j][2]);
            }

            bool is_Valid = true;
            for(int k=0;k<3;k++){
                if(temp[k] != target[k]){
                    is_Valid = false;
                    break;
                }
            }

            if(is_Valid){
                return true;
            }
        }
        return false;
    }
};
