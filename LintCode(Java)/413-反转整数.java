public class Solution {
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    public int reverseInteger(int n) {
        // Write your code here
        long ans = 0;
    	for (; n != 0; n /= 10) {
    		ans = ans * 10 + n % 10;
    	}
    	if (ans > Integer.MAX_VALUE || ans < Integer.MIN_VALUE) {
    		return 0;
    	}
    	return (int)ans;
    }
}