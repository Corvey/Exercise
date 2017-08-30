/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    public ListNode removeElements(ListNode head, int val) {
        // Write your code here
        ListNode ret = new ListNode(0), pre, p;
    	ret.next = head;
    	pre = ret;
    	while (pre != null) {
    		for (p = pre.next; p != null && p.val == val; p = p.next);
    		pre.next = p;
    		pre = p;
    	}
    	return ret.next;
    }
}