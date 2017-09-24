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
     * @return: Level order a list of lists of integer
     */
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        // write your code here
        class MyNode {
    		TreeNode treeNode;
    		int depth;
    		public MyNode(TreeNode treeNode, int depth) {
    			this.treeNode = treeNode;
    			this.depth = depth;
    		}
    	}
    	ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
    	if (root == null) {
    		return ret;
    	}
    	ArrayList<Integer> list;
    	Queue<MyNode> queue = new LinkedList<>();
    	MyNode myNode = new MyNode(root, 1);
    	TreeNode treeNode;
    	queue.add(myNode);
    	while (!queue.isEmpty()) {
    		myNode = queue.poll();
    		treeNode = myNode.treeNode;
    		if (ret.size() < myNode.depth) {
    			list = new ArrayList<>();
    			ret.add(list);
    			list.add(treeNode.val);
    		} else {
    			list = ret.get(myNode.depth - 1);
    			list.add(treeNode.val);
    		}
    		if (treeNode.left != null) {
    			queue.add(new MyNode(treeNode.left, myNode.depth + 1));
    		}
    		if (treeNode.right != null) {
    			queue.add(new MyNode(treeNode.right, myNode.depth + 1));
    		}
    	}
    	return ret;
    }
}