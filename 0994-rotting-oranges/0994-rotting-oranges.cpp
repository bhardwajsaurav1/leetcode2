class Solution {
public:
    vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>qt;
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    qt.push({i,j});
                    visited[i][j]=true;
                }
                if(grid[i][j]==0) visited[i][j]=true;
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int count=-1;
        while(!qt.empty()){
             count++;
            int size=qt.size();
            for(int i=0;i<size;i++){
                int curr_i=qt.front().first;
                int curr_j=qt.front().second;
                qt.pop();
                for(vector<int>dir:direction){
                    int new_i=curr_i+dir[0];
                    int new_j=curr_j+dir[1];
                    if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&visited[new_i][new_j]==false){
                        qt.push({new_i,new_j});
                        fresh--;
                        visited[new_i][new_j]=true;
                    }
                }
            }
            
        }
        cout<<fresh;
       return (fresh==0)?count:-1;
    }
};