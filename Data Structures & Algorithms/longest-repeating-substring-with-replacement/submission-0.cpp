class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int n = s.length();
        int max_freq = INT_MIN;
        int ans = INT_MIN;
        int l = 0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;

            max_freq = max(max_freq,mp[s[r]]);

            while((r-l+1) - max_freq > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
