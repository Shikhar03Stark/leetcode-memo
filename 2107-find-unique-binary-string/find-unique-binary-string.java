/*
Solving using Trie
Pick the bit that does not exists and then pad with 0 to get n bits.
*/

class TrieNode {
    private int value; // 0 or 1
    private TrieNode[] next;

    public TrieNode(int value) {
        this.value = value;
        next = new TrieNode[2];
    }

    public int getValue() { return value; }

    public TrieNode getNext(int value) {
        if (value < 0 || value > 1) return null;
        return next[value];
    }

    public void setNext(int value, TrieNode node) {
        if (value < 0 || value > 1) return;
        next[value] = node;
    }
}

class Solution {

    private TrieNode root = new TrieNode(2);
    
    private void insertInTrie(String s) {
        TrieNode node = root;
        for(char c: s.toCharArray()) {
            int value = c - '0';
            TrieNode next;
            if ( (next = node.getNext(value)) == null) {
                next = new TrieNode(value);
                node.setNext(value, next);
            }
            node = next;
        }
    }

    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        for(String s: nums) {
            insertInTrie(s);
        }

        TrieNode node = root;
        StringBuilder sb = new StringBuilder();
        boolean foundMisMatch = false;
        for(int i = 0; i<n; i++) {
            if (foundMisMatch) {
                sb.append(0);
                continue;
            }
            int pick = 0;
            if (node.getNext(0) != null && node.getNext(1) != null) {
                sb.append(0);
            }
            else if(node.getNext(0) == null) {
                sb.append(0);
                foundMisMatch = true;
            }
            else {
                sb.append(1);
                pick = 1;
                foundMisMatch = true;
            }
            node = node.getNext(pick);
        }

        return sb.toString();
    }
}