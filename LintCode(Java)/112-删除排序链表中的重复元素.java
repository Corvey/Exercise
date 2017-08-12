/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param ListNode head is the head of the linked list
     * @return: ListNode head of linked list
     */
    public static ListNode deleteDuplicates(ListNode head) { 
        // write your code here
    	if (head == null) {
    		return null;
    	}
    	ListNode ret = new ListNode(head.val), tail = ret;
    	for (ListNode p = head.next; p != null; p = p.next) {
    		if (p.val != tail.val) {
    			tail.next = new ListNode(p.val);
    			tail = tail.next;
    		}
    	}
    	return ret;
    }  
}