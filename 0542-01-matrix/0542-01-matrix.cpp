class Solution {
public:
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> qt;

        // Step 1: Enqueue all 0s and mark all 1s as -1 (unvisited)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    qt.push({i, j});
                } else {
                    mat[i][j] = -1; 
                }
            }
        }

        // Step 2: BFS directly modifying mat
        while (!qt.empty()) {
            auto [curr_i, curr_j] = qt.front();
            qt.pop();

            for (auto dir : direction) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                // If neighbor is within bounds and unvisited (-1)
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && mat[new_i][new_j] == -1) {
                    mat[new_i][new_j] = mat[curr_i][curr_j] + 1;
                    qt.push({new_i, new_j});
                }
            }
        }

        return mat;
    }
};