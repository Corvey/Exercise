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
     * @return a ListNode
     */
    public ListNode swapPairs(ListNode head) {
        // Write your code here
    	if (head == null) {
    		return null;
    	}
    	ListNode ret = new ListNode(0);
    	ret.next = head;
    	ListNode pre = ret, p1 = head, p2 = head.next, p3;
    	while (p2 != null) {
    		p3 = p2.next;
    		pre.next = p2;
    		p2.next = p1;
    		p1.next = p3;
    		if (p3 == null) {
    			break;
    		} else {
    			pre = p1;
    			p1 = p3;
    			p2 = p1.next;
    		}
    	}
    	return ret.next;
    }
}