class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(2);
        for(auto& e: nums) {
            if (e < 0) {
                v[1].push_back(e);
            }
            else {
                v[0].push_back(e);
            }
        }

        for(int i = n-1; i>=0; i--) {
            nums[i] = v[i%2].back();
            v[i%2].pop_back();
        }
        return nums;
    }
};