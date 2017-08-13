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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // write your code here
    	ListNode ret = new ListNode(0), tail = ret;
    	ListNode p1 = l1, p2 = l2, temp;
    	if (p2 == null) {
    		temp = p1; p1 = p2; p2 = temp;
    	}
    	for (; p1 != null && p2 != null; p1 = p1.next) {
    		if (p1.val > p2.val) {
    			temp = p1; p1 = p2; p2 = temp;
    		}
    		tail.next = new ListNode(p1.val);
    		tail = tail.next;
    	}
    	for (; p2 != null; p2 = p2.next) {
    		tail.next = new ListNode(p2.val);
    		tail = tail.next;
    	}
    	return ret.next;
    }
}