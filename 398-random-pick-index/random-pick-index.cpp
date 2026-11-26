class Solution {
    unordered_map<int, vector<int>> inv;
    unordered_map<int, uniform_int_distribution<size_t>> dist;
    mt19937 rand_gen{random_device{}()};
public:
    Solution(vector<int>& nums) {
        for(size_t i = 0; i<nums.size(); i++) {
            inv[nums[i]].push_back(i);
        }
        for(size_t i = 0; i<nums.size(); i++) {
            if(!dist.contains(nums[i])) {
                dist[nums[i]] = uniform_int_distribution<size_t>(0, inv.at(nums[i]).size()-1);
            }
        }
    }
    
    int pick(int target) {
        int idx = dist.at(target)(rand_gen);
        return inv[target].at(idx);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */