class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0; // min possible no. of unmatched '('
        int mx = 0; // max possible no. of unmatched '('

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                mn++;
                mx++;
            }
            else if(s[i] == ')'){
                mn--;
                mx--;
            }
            else{
                mn--;
                mx++;
            }

            if(mx<0){
                return false;
            }
            if(mn<0){
                mn = 0;
            }
        }
        return mn == 0;
    }
};
