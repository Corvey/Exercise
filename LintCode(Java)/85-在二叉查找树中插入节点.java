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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    public TreeNode insertNode(TreeNode root, TreeNode node) {
        // write your code here
    	if (root == null) {
    		return node;
    	}
    	TreeNode treeNode = root;
    	boolean done = false;
    	while (!done) {
    		if (node.val < treeNode.val) {
    			if (treeNode.left != null) {
    				treeNode = treeNode.left;
    			} else {
    				treeNode.left = node;
    				done = true;
    			}
    		} else {
    			if (treeNode.right != null) {
    				treeNode = treeNode.right;
    			} else {
    				treeNode.right = node;
    				done = true;
    			}
    		}
    	}
    	return root;
    }
}