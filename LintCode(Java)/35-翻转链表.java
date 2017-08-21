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
     * @param head: The head of linked list.
     * @return: The new head of reversed linked list.
     */
    public ListNode reverse(ListNode head) {
        // write your code here
       ListNode ret = null, cur = head, next;
    	while (cur != null) {
    		next = cur.next;
    		cur.next = ret;
    		ret = cur;
    		cur = next;
    	}
    	return ret;
    }
}
