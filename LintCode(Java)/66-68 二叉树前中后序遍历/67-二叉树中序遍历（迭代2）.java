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
     * @return: Inorder in ArrayList which contains node values.
     */
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        // write your code here
        class MyNode {
    		public TreeNode treeNode;
    		public boolean isTraversal;	//true代表遍历，false代表记录
    		public MyNode(TreeNode treeNode, boolean isTraversal) {
    			this.treeNode = treeNode;
    			this.isTraversal = isTraversal;
    		}
    	}
    	ArrayList<Integer> list = new ArrayList<>();
    	Stack<MyNode> stack = new Stack<>();
		if (root != null) {
			MyNode myNode = new MyNode(root, true);
			TreeNode treeNode;
			stack.push(myNode);
			while (!stack.empty()) {
				myNode = stack.pop();
				treeNode = myNode.treeNode;
				if (myNode.isTraversal == true) {
					if (treeNode.right != null)
						stack.push(new MyNode(treeNode.right, true));
					stack.push(new MyNode(treeNode, false));
					if (treeNode.left != null)
						stack.push(new MyNode(treeNode.left, true));
				} else {
					list.add(treeNode.val);
				}
			}
		}
		return list;
    }
}