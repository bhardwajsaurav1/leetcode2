class Solution {
public:
    vector<vector<int>>direction={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        //vector<vector<int>>ans(m,vector<int>(n));
        queue<pair<int,int>>qt;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                mat[i][j]=0;
                qt.push({i,j});
                }
                else mat[i][j]=-1;
            }
        }
        while(!qt.empty()){
            int size=qt.size();
            for(int i=0;i<size;i++){
                int curr_i=qt.front().first;
                int curr_j=qt.front().second;
                qt.pop();
                for(vector<int> &dir:direction){
                    int new_i=curr_i+dir[0];
                    int new_j=curr_j+dir[1];
                    if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&mat[new_i][new_j]==-1){
                        mat[new_i][new_j]=mat[curr_i][curr_j]+1;
                        qt.push({new_i,new_j});
                    }
                }
            }
        }
        return mat;
    }
};