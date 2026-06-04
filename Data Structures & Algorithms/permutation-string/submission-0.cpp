class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s1[i]]++;
        }
        int count = mp.size();
        int left = 0, right = 0;
        while(right<s2.length()){
            if(mp.find(s2[right])!=mp.end()){
                mp[s2[right]]--;
                if(mp[s2[right]] == 0){
                    count--;
                }
            }

            //Shrinking strategy
            if(right-left+1>n){
                if(mp.find(s2[left])!=mp.end()){
                    if(mp[s2[left]] == 0){
                        count++;
                    }
                    mp[s2[left]]++;
                }
                left++;
            }
            if(count == 0){
                return true;
            }
            right++;
        }
        return false;
    }
};
