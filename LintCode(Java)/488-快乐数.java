public class Solution {
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    public boolean isHappy(int n) {
        // Write your code here
        boolean[] cnt = new boolean[731];
    	int sum, t;
    	while (true) {
    		for (sum = 0; n != 0; n /= 10) {
    			t = n % 10;
    			sum += t * t;
    		}
    		if (sum == 1) {
    			return true;
    		} else if (cnt[sum] == true) {
    			return false;
    		} else {
    			cnt[sum] = true;
    			n = sum;
    		}
    	}
    }
}