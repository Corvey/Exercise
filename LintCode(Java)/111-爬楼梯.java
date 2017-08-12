public class Solution {
    /**
     * @param n: An integer
     * @return: An integer
     */
    public int climbStairs(int n) {
        // write your code here
    	if (n == 0) {
    		return 1;
    	}
    	int a = 1, b = 2;
    	for (int i=2; i<n; i+=2) {
    		a += b;
    		b += a;
    	}
    	return (n&1) == 1 ? a : b;
    }
}