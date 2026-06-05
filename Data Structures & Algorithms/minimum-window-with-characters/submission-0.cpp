class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int start_index = 0;
        int n = t.length();
        int m = s.length();
        int min_length = INT_MAX;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[t[i]]++;
        }
        int count = n;
        for(int r=0;r<m;r++){
            if(mp[s[r]]>0){
                count--;
            }
            mp[s[r]]--;
            //Valid condition:
            while(count == 0){
                if(r-l+1 <min_length){
                    min_length = r-l+1;
                    start_index = l;
                }

                if(mp[s[l]] == 0){
                    count++;
                }
                mp[s[l]]++;
                l++;
            }
        }
        return min_length == INT_MAX ? "":s.substr(start_index, min_length);
    }
};
