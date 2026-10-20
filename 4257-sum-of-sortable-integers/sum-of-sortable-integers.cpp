class Solution {
public:

    // 12
    // 12, 1 : 12
    // 6, 2 : 6
    // 2, 3 : 2
    //
    vector<int> divisors(int n) {
        vector<int> divs;
        for(int i = 1; i*i<=n; i++) {
            if (n % i == 0) {
                if (n % i == 0) {
                    if (n/i != i) divs.push_back(n/i);
                    divs.push_back(i);
                }
            }
        }

        return divs;
    }

    bool isSortable(const vector<int> &nums, int k) {
        int n = nums.size();
        bool possible = true;
        // cout << "K: " << k << '\n';
        for(int start = 0; start < n; start += k) {
            if (is_sorted(nums.begin() + start, nums.begin() + start + k)) continue;
            int neg_cnt = nums[start] - nums[start+k-1] < 0 ? 1 : 0;
            for(int i = start+1; i<start+k; i++) {
                int diff = nums[i] - nums[i-1];
                if (diff < 0) neg_cnt++;
            }
            // cout << "ng " << neg_cnt << '\n';
            if (neg_cnt > 1) {
                possible = false;
                break;
            }
        }
        return possible;
        
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> divs = divisors(n);
        bool sorted = is_sorted(nums.begin(), nums.end());
        if (sorted) {
            return accumulate(divs.begin(), divs.end(), 0);
        }
        int total = 0;
        for(auto& e: divs) {
            // cout << "div: " << e << '\n';
            int prev_min = 0, prev_max = 0;
            int curr_min = 0, curr_max = 0;
            bool inc_seq = true;
            for(int i = 0; i<n; i++) {
                if (i % e == 0) {
                    // check 
                    // cout << "i: " << i << "| ";
                    // cout << "prev: " << prev_min << "," << prev_max << " ";
                    // cout << "curr: " << curr_min << "," << curr_max << "\n";
                    if (curr_min < prev_max && i >= 2*e) {
                        inc_seq = false;
                        break;
                    }
                    prev_min = curr_min;
                    prev_max = curr_max;
                    curr_min = nums[i];
                    curr_max = nums[i];
                }
                curr_min = min(curr_min, nums[i]);
                curr_max = max(curr_max, nums[i]);
            }
            if (curr_min < prev_max) inc_seq = false;
            if (!inc_seq) continue;
            if (isSortable(nums, e)) total += e;
        }

        return total;
    }
};