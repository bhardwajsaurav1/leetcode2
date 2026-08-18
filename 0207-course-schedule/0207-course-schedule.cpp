class Solution {
public:// this is the question of finding cycle in directed graph
    bool dfs(vector<bool>&visited, vector<bool>&current, int u, vector<vector<int>>&adj){
        visited[u]=true;
        current[u]=true;
        for(auto v:adj[u]){
            if(visited[v]&& current[v]) return true;
            if(!visited[v]&&dfs(visited, current, v, adj)) return true;
        }
        current[u]=false;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        for(auto temp:pre){
            adj[temp[0]].push_back(temp[1]);
        }
        vector<bool>visited(num,false);
        vector<bool>current(num,false);
        for(int i=0;i<num;i++){
            if(!visited[i]&&dfs(visited,current, i, adj)) return false;
        }
        return true;
    }
};