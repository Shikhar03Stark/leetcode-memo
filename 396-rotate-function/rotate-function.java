/*
F(k) = 0*a[k] + 1*a[k+1] + .. + n-2*a[n-2+k]. + n-1*a[n-1+k % n]
F(k+1) = 0*a[k+1] + 1*a[k+2] + ...+ n-2*a[n-1+k] + n-1*a[k]
F(k+1) = F(k) - S[0..n-1] + n*a[k]
*/
class Solution {
    public int maxRotateFunction(int[] nums) {
        int f0 = 0;
        int totalSum = 0;
        for(int i = 0; i<nums.length; i++) {
            f0 += i*nums[i];
            totalSum += nums[i];
        }
        int ans = f0;
        for(int i = 1; i<nums.length; i++) {
            f0 = f0 - totalSum + nums.length * nums[i-1];
            ans = Math.max(ans, f0);
        }
        return ans;
    }
}