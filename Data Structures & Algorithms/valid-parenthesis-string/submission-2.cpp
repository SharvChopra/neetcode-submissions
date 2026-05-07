class Solution {
public:
    bool checkValidString(string s) {
        //Method-1: Greedy method:
        // int mn = 0; // min possible no. of unmatched '('
        // int mx = 0; // max possible no. of unmatched '('

        // for(int i=0;i<s.length();i++){
        //     if(s[i] == '('){
        //         mn++;
        //         mx++;
        //     }
        //     else if(s[i] == ')'){
        //         mn--;
        //         mx--;
        //     }
        //     else{
        //         mn--;
        //         mx++;
        //     }

        //     if(mx<0){
        //         return false;
        //     }
        //     if(mn<0){
        //         mn = 0;
        //     }
        // }
        // return mn == 0;

        //Method-2;
        //Stack -based approach
        stack<char>opening_bracket,star_bracket;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                opening_bracket.push(i);
            }
            else if(s[i] == '*'){
                star_bracket.push(i);
            }
            else{
                if(opening_bracket.empty() && star_bracket.empty()){
                    return false;
                }
                if(!opening_bracket.empty()){
                    opening_bracket.pop();
                }
                else{
                    star_bracket.pop();
                }
            }
        }

        while(!opening_bracket.empty() && !star_bracket.empty()){
            if(opening_bracket.top()>star_bracket.top()){
                return false;
            }
            opening_bracket.pop();
            star_bracket.pop();
        }

        return opening_bracket.empty();
    }
};
