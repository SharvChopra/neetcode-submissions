class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        //To find the last occurence of each character
        for(int i=0;i<s.length();i++){
            mp[s[i]] = i;
        }
        int size = 0;
        int end = 0;
        vector<int>results;
        for(int i=0;i<s.length();i++){
            size++;
            end = max(end,mp[s[i]]);

            if(i==end){
                results.push_back(size);
                size = 0;
            }
        }
        return results;
    }
};
