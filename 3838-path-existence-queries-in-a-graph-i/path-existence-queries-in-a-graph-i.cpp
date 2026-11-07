class Solution {
public:

    int findParent(vector<int> &dsu, int x) {
        return dsu[x] < 0 ? x : dsu[x] = findParent(dsu, dsu[x]);
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> dsu(n, -1);
        for(int i = 1; i<n; i++) {
            // connect with prev?
            if (nums[i] - nums[i-1] <= maxDiff) {
                // merge
                int p1 = findParent(dsu, i), p2 = findParent(dsu, i-1);
                if (p1 != p2) {
                    if (p1 < p2) {
                        swap(p1, p2);
                    }
                    dsu[p1] += dsu[p2];
                    dsu[p2] = p1;
                }
            }
        }

        vector<bool> ans;
        for(auto& q: queries) {
            int u = q[0], v = q[1];
            int pu = findParent(dsu, u), pv = findParent(dsu, v);
            if (pu == pv) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};