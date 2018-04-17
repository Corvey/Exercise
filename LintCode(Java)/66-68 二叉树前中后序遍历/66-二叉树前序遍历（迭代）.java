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
     * @return: Preorder in ArrayList which contains node values.
     */
    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        // write your code here
        ArrayList<Integer> list = new ArrayList<>();
    	Stack<TreeNode> stack = new Stack<>();
    	if (root != null) {
    		stack.push(root);
    		TreeNode node = null;
    		while (!stack.empty()) {
    			node = stack.pop();
    			list.add(node.val);
    			if (node.right != null)
    				stack.push(node.right);
    			if (node.left != null)
    				stack.push(node.left);
    		}
    	}
    	return list;
    }
}