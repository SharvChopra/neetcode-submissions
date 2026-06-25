class Solution {
public:
    bool dfs(int u, int parent, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        visited[u] = true;

        for(auto&v:adj[u]){
            if(!visited[v]){
                if(!dfs(v,u,adj,visited)) return false;
            }
            else if(v!=parent){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        unordered_map<int,vector<int>>adj(n);
        for(auto& e:edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,0);

        //Loop checking
        if(!dfs(0,-1,adj,visited)) return false;

        //CHECK if there is disconnectivity
        for(int i=0;i<n;i++){
            if(visited[i] == false) return false;
        }
        return true;
    }
};
