class Solution {
public:
// since every path will end at edge thus in order to check which have proper path, we can use bfs from edges of O
    vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>qt;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') qt.push({i,0});
            if(board[i][n-1]=='O') qt.push({i,n-1});
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') qt.push({0,j});
            if(board[m-1][j]=='O') qt.push({m-1,j});
        }
        // while(!qt.empty()){
        //     cout<<qt.front().first<<" "<<qt.front().second<<endl;
        //     qt.pop();
        // }
        while(!qt.empty()){
            int size=qt.size();
            for(int i=0;i<size;i++){
                int curr_i=qt.front().first;
                int curr_j=qt.front().second;
                board[curr_i][curr_j]='#';
                qt.pop();
                for(vector<int>& dir:direction){
                    int new_i=curr_i+dir[0];
                    int new_j=curr_j+dir[1];
                    if(new_i>=0&&new_i<m&&new_j<n&&new_j>=0&& board[new_i][new_j]=='O'){
                        qt.push({new_i,new_j});
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};