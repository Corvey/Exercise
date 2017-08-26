public class Solution {
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    public int[] plusOne(int[] digits) {
        // Write your code here
        int n = digits.length;
    	Stack<Integer> stack = new Stack<>();
    	boolean isCarry = true;
    	for (int i=n-1; i>0; --i) {
    		if (isCarry == true) {
    			if (digits[i] == 9) {
    				stack.push(0);
    			} else {
    				stack.push(digits[i] + 1);
        			isCarry = false;
    			}
    		} else {
    			stack.push(digits[i]);
    		}
    	}
    	if (isCarry == true) {
			if (digits[0] == 9) {
				stack.push(0);
				stack.push(1);
			} else {
				stack.push(digits[0] + 1);
			}
		} else {
			stack.push(digits[0]);
		}
    	n = stack.size();
    	int[] ret = new int[n];
    	for (int i=0; i<n; ++i) {
    		ret[i] = stack.pop();
    	}
    	return ret;
    }
}