/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param A: an integer array
     * @return: a tree node
     */
    public TreeNode sortedArrayToBST(int[] A) {  
        // write your code here
    	class Iter {
    		int[] data;
    		public Iter(int[] data) {
    			this.data = data;
    		}
    		public TreeNode work(int l, int r) {
    			if (l > r) {
    				return null;
    			} else if (l == r) {
    				return new TreeNode(data[l]);
    			} else {
    				int mid = l + (r - l >> 1);
    				TreeNode node = new TreeNode(data[mid]);
    				node.left = work(l, mid-1);
    				node.right = work(mid+1, r);
    				return node;
    			}
    		}
    	}
    	int len = A.length;
    	if (len == 0) {
    		return null;
    	}
    	Iter iter = new Iter(A);
    	return iter.work(0, len-1);
    }  
}
