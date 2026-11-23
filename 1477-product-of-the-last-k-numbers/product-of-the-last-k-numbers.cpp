class ProductOfNumbers {
    using ll = long long;
    vector<ll> nums;
    ll total_mul = 1;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            total_mul = 1;
            nums.clear();
        }
        else {
            total_mul *= (ll)num;
            if (nums.empty()) {
                nums.push_back(num);
            }
            else {
                nums.push_back(nums.back() * num);
            }
        }
    }
    
    int getProduct(int k) {
        int n = nums.size();
        if (k > n) return 0;
        else if (k == n) return total_mul;
        else return total_mul / nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */