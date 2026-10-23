class Solution {
    unordered_map<char,char> next_color;
public:
    Solution() {
        next_color['R'] = 'B';
        next_color['B'] = 'W';
        next_color['W'] = 'R';
    }
// cycle of R B W R only

    bool dfsPattern(const vector<vector<int>> &gp, const string& colors, int node, int parent) {
        char curr = colors[node];
        // cout << node << " ";
        for(auto& next: gp[node]) {
            if (next == parent) continue;
            char next_col = colors[next];
            if (next_col != next_color[curr]) {
                return false;
            }
            if (!dfsPattern(gp, colors, next, node)) return false;
        }
        return true;
    }

    int colorIdx(char c) {
        switch (c) {
            case 'R': return 0;
            case 'B': return 1;
            case 'W': return 2;
            default: return -1;
        }
    }

    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> indeg(n, 0), outdeg(n, 0);
        // vector<vector<int>> gp(n);
        for(auto& e: edges) {
            int u = e[0], v = e[1];
            int uc = colorIdx(colors[u]), vc = colorIdx(colors[v]);
            if (uc == vc) return -1;
            if ((uc+1) % 3 == vc) {
                indeg[v]++;
                outdeg[u]++;
            }
            else {
                indeg[u]++;
                outdeg[v]++;
            }
        }

        int root = -1;
        for(int i = 0; i<n; i++) {
            if (indeg[i] == 0 && outdeg[i] <= 2) {
                if (root != -1) return -1;
                root = i;
            }
        }
        for(int i = 0; i<n; i++) {
            if (i == root) continue;
            if (indeg[i] > 1) return -1;
        }
        return root;

        return -1;
    }
};