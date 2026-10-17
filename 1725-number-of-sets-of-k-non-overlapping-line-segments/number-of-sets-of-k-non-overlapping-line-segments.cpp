class Solution {
public:
    using ll = long long;
    const ll mod = 1e9+7;
    ll solve(int n, int k, vector<vector<ll>> &dp) {
        if (k == n-1 || k == 0) return 1;
        if (n <= k) return 0;
        if (dp[n][k] != -1) return dp[n][k];
        ll ans = 0;
        for(int len = 0; len < n; len++) {
            if (len == 0)
                ans += solve(n-1, k, dp);
            else
                ans += solve(n-len, k-1, dp);

            ans %= mod;
        }
        return dp[n][k] = ans;
    }

    int numberOfSets(int n, int k) {
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, -1));
        return solve(n, k, dp);

    }
};