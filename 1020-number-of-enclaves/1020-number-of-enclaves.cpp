class Solution {
public:
    vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> qt;
        for(int i=0;i<m;i++){
            if(grid[i][0]){
                qt.push({i,0});
                grid[i][0]=-1;
            } 
            if(grid[i][n-1]){
                qt.push({i,n-1});
                grid[i][n-1]=-1;
            } 
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]){
                qt.push({0,j});
                grid[0][j]=-1;
            } 
            if(grid[m-1][j]){
                qt.push({m-1,j});
                grid[m-1][j]=-1;
            }
        }
        while(!qt.empty()){
            int curr_i=qt.front().first;
            int curr_j=qt.front().second;
            qt.pop();
            for(vector<int>&dir:direction){
                int new_i=curr_i+dir[0];
                int new_j=curr_j+dir[1];
                if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&grid[new_i][new_j]==1){
                    qt.push({new_i,new_j});
                    grid[new_i][new_j]=-1;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};