/**
 * Definition for singly-linked list.
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    public ListNode addLists(ListNode l1, ListNode l2) {
        // write your code here
        ListNode p1 = l1, p2 = l2;
    	ArrayList<Integer> list = new ArrayList<>();
    	for (; p1 != null && p2 != null; p1 = p1.next, p2 = p2.next) {
    		list.add(p1.val + p2.val);
    	}
    	for (p1 = p1 != null ? p1 : p2; p1 != null; p1 = p1.next) {
    		list.add(p1.val);
    	}
    	ListNode ret = new ListNode(0);
    	p1 = ret;
    	boolean isCarry = false;
    	for (int x : list) {
    		if (isCarry == true) {
    			if (x >= 9) {
    				p1.next = new ListNode(x+1-10);
    			} else {
    				p1.next = new ListNode(x+1);
    				isCarry = false;
    			}
    		} else if (x >= 10) {
    			p1.next = new ListNode(x-10);
				isCarry = true;
    		} else {
    			p1.next = new ListNode(x);
    		}
    		p1 = p1.next;
    	}
    	if (isCarry == true) {
    		p1.next = new ListNode(1);
    	}
    	return ret.next;
    }
}