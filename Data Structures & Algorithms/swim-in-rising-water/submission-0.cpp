class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>dist(n*n,INT_MAX);
        dist[0] = grid[0][0];
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({grid[0][0],0});

        while(!pq.empty()){
            auto [water_level_so_far,idx] = pq.top();
            pq.pop();

            if(water_level_so_far > dist[idx]){
                continue;
            }

            if(idx == n*n-1){
                return water_level_so_far;
            }
            int r = idx/n;
            int c = idx%n;
            for(auto dir:directions){
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int neighbor_idx = nr*n+nc;
                    int water_level_updated = max(water_level_so_far,grid[nr][nc]);

                    if(water_level_updated < dist[neighbor_idx]){
                        dist[neighbor_idx] = water_level_updated;
                        pq.push({water_level_updated, neighbor_idx});
                    }
                }
            }
        }
        return -1;
    }
};
