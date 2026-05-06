class Solution {
public:
//Method - 1 => using DFS
    // void dfs(int u,vector<bool>&visited,unordered_map<int,vector<int>>&mp){
    //     visited[u] = true;

    //     for(int v:mp[u]){
    //         if(!visited[v]){
    //             dfs(v,visited,mp);
    //         }
    //     }
    //     return;
    // }
    // int countComponents(int n, vector<vector<int>>& edges) {
    //     //using DFS
    //     //Making Graph Step - 1
    //     unordered_map<int,vector<int>>mp;
    //     for(auto &vec:edges){
    //         mp[vec[0]].push_back(vec[1]);
    //         mp[vec[1]].push_back(vec[0]);
    //     }
    //     vector<bool>visited(n,false);
    //     // To find the number of components;
    //     int result = 0; 
    //     for(int i=0;i<n;i++){
    //         if(!visited[i]){
    //             dfs(i,visited,mp);
    //             result++;
    //         }
    //     }
    //     return result;
    // }

    //Using DSU(Disjoint Union Set)
    //Write Find and Union Functions
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int countComponents(int n,vector<vector<int>>&edges){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        int components = n;
        for(auto &v:edges){
            if(find(v[0])!=find(v[1])){
                Union(v[0],v[1]);
                components--;
            }
        }

        return components;
    }
};
