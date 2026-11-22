class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int a_last = -1, b_first = n;
        for(int i = 0; i<n; i++) {
            if (s[i] == 'a') {
                a_last = i;
            }
            else {
                if (b_first == n) {
                    b_first = i;
                }
            }
        }

        return a_last < b_first;
    }
};