class Solution {
public:
    int m,n;
    const int INF = 2147483647;
    vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};

    int bfs(vector<vector<int>>&grid,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});

        vector<vector<bool>>visited(m,vector<bool>(n,false));
        visited[i][j]=true;

        int steps = 0;

        while(!q.empty()){
            
            int size = q.size();

            for(int i=0;i<size;i++){
                auto [nr,nc] = q.front();
                q.pop();
                if(grid[nr][nc]==0) return steps;
                for(auto & dir:directions){
                    int row = nr+dir[0];
                    int col = nc+dir[1];

                    if(row>=0 && row<m && col>=0 && col<n && grid[row][col]!=-1 && !visited[row][col]){
                        visited[row][col] = true;
                        q.push({row,col});
                    }
                }
            }
            steps++;
        }
        return INF;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==INF){
                    grid[i][j] = bfs(grid,i,j);
                }
            }
        }
    }
};
