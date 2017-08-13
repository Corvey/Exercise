import java.util.Queue;

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
     * @return: An integer.
     */
    public int minDepth(TreeNode root) {
        // write your code here
    	class MyNode {
    		TreeNode treeNode;
    		int depth;
    		public MyNode(TreeNode treeNode, int depth) {
    			this.treeNode = treeNode;
    			this.depth = depth;
    		}
    		public MyNode newByLeft() {
    			return new MyNode(treeNode.left, depth+1);
    		}
    		public MyNode newByRight() {
    			return new MyNode(treeNode.right, depth+1);
    		}
    	}
    	if (root == null) {
    		return 0;
    	}
    	Queue<MyNode> queue = new LinkedList<>();
    	MyNode myNode = new MyNode(root, 1);
    	TreeNode treeNode;
    	int ans = 1;
    	queue.add(myNode);
    	while (!queue.isEmpty()) {
    		myNode = queue.poll();
    		treeNode = myNode.treeNode;
    		if (treeNode.left == null && treeNode.right == null) {
    			ans = myNode.depth;
    			break;
    		}
    		if (treeNode.left != null) {
    			queue.add(myNode.newByLeft());
    		}
    		if (treeNode.right != null) {
    			queue.add(myNode.newByRight());
    		}
    	}
    	queue.clear();
    	return ans;
    }
}