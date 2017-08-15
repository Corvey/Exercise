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
     * @return: The head of linked list.
     */
    public ListNode insertionSortList(ListNode head) {
        // write your code here
    	if (head == null) {
    		return null;
    	}
    	ListNode ret = new ListNode(0);
    	ret.next = new ListNode(head.val);
    	ListNode p2, pre, newNode;
    	for (ListNode p1 = head.next; p1 != null; p1 = p1.next) {
    		pre = ret; p2 = pre.next;
    		for (; p2 != null && p1.val > p2.val; pre = p2, p2 = p2.next);
    		newNode = new ListNode(p1.val);
    		newNode.next = p2;
    		pre.next = newNode;
    	}
    	return ret.next;
    }
}