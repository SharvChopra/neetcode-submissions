class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        for(char &ch:s){
            ch = tolower(ch);
        }
        erase_if(s,[](unsigned char ch){
            return !isalnum(ch);
        });
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i] != s[j]){
               return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
