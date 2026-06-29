class Solution {
   public:
    bool isValid(int r,int c,int n, vector<vector<bool>>&visited){
        //straight up that column
        for(int i=0;i<r;i++){
            if(visited[i][c]) return false;
        }

        //top-left
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(visited[i][j]) return false;
        }

        //top-right;
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
            if(visited[i][j]) return false;
        }

        return true;
    }
    void backtrack(int r, vector<string>& res, vector<vector<string>>& result,
                   vector<vector<bool>>& visited,int n) {
                    if(r == n){
                        result.push_back(res);
                        return;
                    }
                    for(int c=0;c<n;c++){
                        if(isValid(r,c,n,visited)){
                            res[r][c] = 'Q';
                            visited[r][c] = true;
                            backtrack(r+1,res,result,visited,n);
                            res[r][c] = '.';
                            visited[r][c] = false;
                        }
                    }

                   }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> res(n, string(n, '.'));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        backtrack(0, res, result, visited,n);
        return result;
    }
};
