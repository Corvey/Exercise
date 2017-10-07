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
     * @param x: an integer
     * @return: a ListNode 
     */
    public ListNode partition(ListNode head, int x) {
        // write your code here
    	if (head == null) {
    		return null;
    	}
    	ListNode less = new ListNode(0);
    	ListNode greater = new ListNode(0);
    	ListNode pLess = less, pGreater = greater;
    	for (ListNode p = head; p != null; p = p.next) {
    		if (p.val < x) {
    			pLess.next = new ListNode(p.val);
    			pLess = pLess.next;
    		} else {
    			pGreater.next = new ListNode(p.val);
    			pGreater = pGreater.next;
    		}
    	}
    	pLess.next = greater.next;
    	return less.next;
    }
}
