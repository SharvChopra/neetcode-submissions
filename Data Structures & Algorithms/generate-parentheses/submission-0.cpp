class Solution {
   public:
    void backtrack(int openCount, int closeCount, int n, string& ans, vector<string>& result) {
        if(openCount == n && closeCount==n){
            result.push_back(ans);
            return;
        }
        if(openCount < n){
            ans.push_back('(');
            backtrack(openCount+1,closeCount,n,ans,result);
            ans.pop_back();
        }

        if(closeCount < openCount){
            ans.push_back(')');
            backtrack(openCount,closeCount+1,n, ans, result);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // Maintain a count;
        vector<string> result;
        string ans = "";
        backtrack(0, 0, n, ans, result);
        return result;
    }
};
