class Solution {
public:

    void dfs(const vector<vector<int>> &gp, const string& s, int node, int parent, unordered_map<char, int> &mp, vector<int> &diff) {
        char color = s[node];
        int above = -1;
        if (mp.contains(color) && mp.at(color) >= 0) {
            int pnode = mp.at(color);
            above = pnode;
            // diff[pnode]++;
        }
        mp[s[node]] = node;
        for(auto& next: gp[node]) {
            dfs(gp, s, next, node, mp, diff);
            // diff[node] += diff[next];
        }
        mp[s[node]] = above;
        if (node > 0)
            diff[above == -1 ? parent : above] += diff[node];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        // vector<int> pp(n, -1);
        // vector<int> ans(n, 0);
        // for(int i = 0; i<n; i++) {
        //     if (i == 0) continue;
        //     char color = s[i];
        //     int anc_node = -1;
        //     int node = i;
        //     while(parent[node] != -1) {
        //         int p = parent[node];
        //         if (s[p] == color) {
        //             anc_node = p;
        //             break;
        //         }
        //         node = parent[node];
        //     }
        //     if (anc_node >= 0) {
        //         ans[anc_node]++;
        //         pp[i] = anc_node;
        //     }
        //     else {
        //         ans[parent[i]]++;
        //         pp[i] = parent[i];
        //     }
        // }
        // vector<int> sz(n);
        // sz[0] = 1;
        // for(int i = 1; i<n; i++) {
        //     int node = i;
        //     sz[node]++;
        //     while(pp[node] != -1) {
        //         sz[pp[node]]++;
        //         node = pp[node];
        //     }
        // }
        // return sz;
        // -------
        vector<vector<int>> gp(n);
        for(int i = 1; i<n; i++) {
            gp[parent[i]].push_back(i);
        }

        vector<int> diff(n, 1);
        unordered_map<char,int> color_mp;
        dfs(gp, s, 0, -1, color_mp, diff);

        // for(int i = 0; i<n; i++) {
        //     sz[i] += diff[i];
        // }
        return diff;
    }
};