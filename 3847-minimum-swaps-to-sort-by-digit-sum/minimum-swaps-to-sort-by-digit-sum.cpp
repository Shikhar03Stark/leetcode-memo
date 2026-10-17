class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        auto digitSum = [](const int& val) ->int {
            int s = 0;
            int v = val;
            while(v > 0) {
                s += v % 10;
                v /= 10;
            }
            return s;
        };
        vector<pair<int,int>> temp;
        for(int i = 0; i<n; i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end(), [digitSum](const pair<int,int>& a, const pair<int,int>& b){
            int asum = digitSum(a.first), bsum = digitSum(b.first);
            return asum == bsum ? a.first < b.first : asum < bsum;
        });
        // for(auto& p: temp) {
        //     cout << p.first << "," << p.second << " ";
        // }
        // cout << '\n';
        int ans = 0;    
        for(int i = 0; i<n; i++) {
            while(temp[i].second != i) {
                swap(temp[temp[i].second], temp[i]);
                ans++;
            }
        }
        return ans;
    }
};