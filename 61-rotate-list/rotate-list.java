/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    private int getSize(ListNode head) {
        int sz = 0;
        ListNode node = head;
        while(node != null) {
            node = node.next;
            sz++;
        }
        return sz;
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return null;
        int sz = getSize(head);
        k = k % sz;
        if (k == 0) return head;

        ListNode newHead = head;
        ListNode follow = head;
        for(int i = 0; i<k; i++) {
            follow = follow.next;
        }
        ListNode prev = null;
        ListNode last = null;
        while(follow != null) {
            prev = newHead;
            last = follow;
            newHead = newHead.next;
            follow = follow.next;
        }

        prev.next = null;
        last.next = head;
        return newHead;
    }
}