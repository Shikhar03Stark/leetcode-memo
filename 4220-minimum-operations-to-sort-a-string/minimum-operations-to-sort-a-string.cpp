class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n == 1) return 0;
        if (n == 2) {
            return s[0] <= s[1] ? 0 : -1;
        }
        if(is_sorted(s.begin(), s.end())) {
            return 0;
        }
        string t = s;
        sort(t.begin(), t.end());
        int first_miss = -1, last_miss = -1;
        for(int i = 0; i<n; i++) {
            if (s[i] != t[i]) {
                if (first_miss == -1) first_miss = i;
                last_miss = i;
            }
        }
        /*
        dcba
        bcda
        bacd
        abcd

        card
        acrd
        acdr
        */
        if (first_miss > 0 || last_miss < n-1) return 1;
        string p1 = s, p2 = s;
        sort(p1.begin(), p1.begin()+n-1);
        sort(p1.begin()+1, p1.end());
        if (p1 == t) return 2;
        sort(p2.begin()+1, p2.end());
        sort(p2.begin(), p2.begin()+n-1);
        if (p2 == t) return 2;
        return 3;
    }
};