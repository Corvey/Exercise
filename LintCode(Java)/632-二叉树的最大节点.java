public class Solution {
    /**
     * @param root the root of binary tree
     * @return the max ndoe
     */
    public TreeNode maxNode(TreeNode root) {
        // Write your code here
        if (root == null) {
    		return null;
    	}
    	TreeNode ret = root, node;
    	Queue<TreeNode> queue = new LinkedList<>();
    	queue.add(root);
    	while (!queue.isEmpty()) {
    		node = queue.poll();
    		if (node.val > ret.val) {
    			ret = node;
    		}
    		if (node.left != null) {
    			queue.add(node.left);
    		}
    		if (node.right != null) {
    			queue.add(node.right);
    		}
    	}
    	return ret;
    }
}