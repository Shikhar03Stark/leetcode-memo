class Solution {
public:

    bool isInside(int row, int col, int m, int n) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> last{0,0};
        set<vector<int>> visited;
        int row = 0, col = 0;
        while(isInside(row, col, m, n)) {
            // cout << "(" << row << "," << col << ")\n";
            if (visited.find({row, col}) != visited.end()) {
                break;
            }
            visited.insert({row, col});
            char direction = grid[row][col];
            last = {row, col};
            switch (direction) {
                case 'L':
                    col--;
                    break;
                case 'R':
                    col++;
                    break;
                case 'U':
                    row--;
                    break;
                default:
                    row++;
            }
        }

        return last;

    }
};