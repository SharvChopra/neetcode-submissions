class Solution {
public:
    void dfs(int u,vector<bool>&visited,unordered_map<int,vector<int>>&mp){
        visited[u] = true;

        for(int v:mp[u]){
            if(!visited[v]){
                dfs(v,visited,mp);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        //using DFS
        //Making Graph Step - 1
        unordered_map<int,vector<int>>mp;
        for(auto &vec:edges){
            mp[vec[0]].push_back(vec[1]);
            mp[vec[1]].push_back(vec[0]);
        }
        vector<bool>visited(n,false);
        // To find the number of components;
        int result = 0; 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,mp);
                result++;
            }
        }
        return result;
    }
};
