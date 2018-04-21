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
     * @param root: The root of binary tree.
     * @return: Postorder in ArrayList which contains node values.
     */
    public ArrayList<Integer> postorderTraversal(TreeNode root) {
        // write your code here
        class Iter {
    		public void work(ArrayList list, TreeNode root) {
    			if (root.left != null)
    				work(list, root.left);
    			if (root.right != null)
    				work(list, root.right);
    			list.add(root.val);
    		}
    	}
    	ArrayList<Integer> list = new ArrayList<>();
    	if (root != null) {
    		Iter iter = new Iter();
    		iter.work(list, root);
    	}
    	return list;
    }
}