class Solution {

    private boolean isEqual(String s, String t, int offset) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        for(int i = 0; i<n; i++) {
            int sidx = (i + offset) % n;
            if (s.charAt(sidx) != t.charAt(i)) return false;
        }
        return true;
    }

    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;
        for(int i = 0; i<s.length(); i++) {
            if (isEqual(s, goal, i)) return true;
        }
        return false;
    }
}