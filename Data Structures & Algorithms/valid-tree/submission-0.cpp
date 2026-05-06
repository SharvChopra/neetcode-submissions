class Solution {
public:
    bool isCycleDFS(int u,int parent,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        visited[u] = true;
        
        for(int &v:adj[u]){
            if(!visited[v]){
                if(isCycleDFS(v,u,adj,visited)){
                    return true;
                }
            }
            else if(v!=parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;

        unordered_map<int,vector<int>>adj;
        for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        vector<bool>visited(n,false);

        if(isCycleDFS(0,-1,adj,visited)){
            return false;
        }

        for(bool v:visited){
            if(!v){
                return false;
            }
        }
    }
};
