class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min_elem = *min_element(nums.begin(), nums.end());
        int ops = 0;
        for(auto& e: nums) {
            ops += e - min_elem;
        }
        return ops;
    }
};