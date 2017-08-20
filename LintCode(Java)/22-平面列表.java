/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class Solution {

    // @param nestedList a list of NestedInteger
    // @return a list of integer
    public List<Integer> flatten(List<NestedInteger> nestedList) {
        // Write your code here
        class MyNode {
    		List<NestedInteger> list;
    		int cur = 0, len;
    		public MyNode(List<NestedInteger> list) {
    			this.list = list;
    			len = list.size();
    		}
    		public boolean isEmpty() {
    			return cur == len;
    		}
    		public NestedInteger getNext() {
    			return list.get(cur++);
    		}
    	}
    	ArrayList<Integer> list = new ArrayList<>();
    	Stack<MyNode> stack = new Stack<>();
    	MyNode node = new MyNode(nestedList);
    	stack.push(node);
    	NestedInteger ni;
    	while (!stack.isEmpty()) {
    		node = stack.peek();
    		if (node.isEmpty()) {
    			stack.pop();
    			continue;
    		}
    		do {
    			ni = node.getNext();
    			if (ni.isInteger()) {
    				list.add(ni.getInteger());
    			} else {
    				stack.push(new MyNode(ni.getList()));
    				break;
    			}
    		} while (!node.isEmpty());
    	}
    	return list;
    }
}