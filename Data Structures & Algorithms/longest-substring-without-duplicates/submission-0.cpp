class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        int l = 0;
        int max_length = INT_MIN;
        for(int r=0;r<n;r++){
            mp[s[r]]++;

            while(mp[s[r]]>1){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            max_length = max(max_length, r-l+1);
        }
        return max_length;
    }
};
