class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> qt;

        // Step 1: Enqueue all 0s and mark 1s as -1 (unvisited)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    qt.push({i, j});
                } else {
                    mat[i][j] = -1; 
                }
            }
        }

        // Direction arrays avoid heap allocations
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        // Step 2: Multi-source BFS
        while (!qt.empty()) {
            auto [r, c] = qt.front();
            qt.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1) {
                    mat[nr][nc] = mat[r][c] + 1;
                    qt.push({nr, nc});
                }
            }
        }

        return mat;
    }
};