class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //  bool x = false,y=false,z=false;
        // for(auto t:triplets){
        //     if(t[0] == target[0] && t[1]<=target[1] && t[2]<=target[2]){
        //         x = true;
        //     }

        //     if(t[0]<=target[0] && t[1]==target[1] && t[2]<=target[2]){
        //         y = true;
        //     }

        //     if(t[0]<=target[0] && t[1]<=target[1] && t[2] == target[2]){
        //         z = true;
        //     }

        //     if(x && y && z){
        //         return true;
        //     }
        // }
        // return false;
        unordered_set<int>s;
    for(const auto t:triplets){
        if(t[0]>target[0] || t[1]>target[1]||t[2]>target[2]){
            continue;
        }

        for(int i=0;i<t.size();i++){
            if(t[i] == target[i]){
                s.insert(i);
            }
        }
    }
    return s.size() == 3;
    }
};
