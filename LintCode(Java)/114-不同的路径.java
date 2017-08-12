public class Solution {
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    public int uniquePaths(int m, int n) {
        // write your code here 
        if (m < n) {
    		return uniquePaths(n, m);
    	}
    	int totalStep = m + n - 2;
    	double ans = 0;
    	for (int i=m; i<=totalStep; ++i) {
    		ans += Math.log(i);
    	}
    	for (int i=2; i<n; ++i) {
    		ans -= Math.log(i);
    	}
    	ans = Math.exp(ans);
    	return (int)Math.round(ans);
    }
}
