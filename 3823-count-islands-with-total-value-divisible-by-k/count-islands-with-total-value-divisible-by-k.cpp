class Solution {
public:
    using ll = long long;
    bool isInside(int r, int c, int row, int col) {
        return r >= 0 && c >= 0 && r < row && c < col;
    }

    ll dfsSum(vector<vector<int>> &grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (!isInside(row, col, m, n) && grid[row][col] <= 0) return 0;
        ll total = grid[row][col];
        grid[row][col] = -1;
        vector<int> dirs{-1, 0, 1, 0, -1};
        for(int k = 0; k<4; k++) {
            int nr = row + dirs[k], nc = col + dirs[k+1];
            if (isInside(nr, nc, m, n) && grid[nr][nc] > 0) {
                total += dfsSum(grid, nr, nc);
                grid[nr][nc] = -1;
            }
        }

        return total;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if (grid[i][j] > 0) {
                    ll total = dfsSum(grid, i, j);
                    if (total % (ll)k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};