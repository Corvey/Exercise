public class Solution {
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return sum of num1 and num2
     */
    public String addStrings(String num1, String num2) {
        // Write your code here
    	if (num2.length() > num1.length()) {
    		return addStrings(num2, num1);
    	}
    	int p1 = num1.length()-1, p2 = num2.length()-1;
    	int[] sum = new int[p1+1];
    	int carry = 0, a, b;
    	for (; p2 >= 0; --p1, --p2) {
    		a = num1.charAt(p1) - '0';
    		b = num2.charAt(p2) - '0';
    		sum[p1] = a + b + carry;
    		if (sum[p1] >= 10) {
    			carry = sum[p1] / 10;
    			sum[p1] %= 10;
    		} else {
    			carry = 0;
    		}
    	}
    	for (; p1 >= 0; --p1) {
    		a = num1.charAt(p1) - '0';
    		sum[p1] = a + carry;
    		if (sum[p1] >= 10) {
    			carry = sum[p1] / 10;
    			sum[p1] %= 10;
    		} else {
    			carry = 0;
    		}
    	}
    	StringBuilder sb = new StringBuilder();
    	if (carry > 0) {
    		sb.append(carry);
    	}
    	for (int i=0; i<sum.length; ++i) {
    		sb.append(sum[i]);
    	}
    	return sb.toString();
    }
}