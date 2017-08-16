/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode removeNthFromEnd(ListNode head, int n) {
        // write your code here
    	ListNode p, dest, pre, ret;
    	p = head;
    	for (int i=0; i<n; ++i, p = p.next);
    	ret = new ListNode(0);
    	ret.next = head;
    	pre = ret;
    	dest = head;
    	for (; p != null; p = p.next, dest = dest.next, pre = pre.next);
    	pre.next = dest.next;
    	return ret.next;
    }
}
