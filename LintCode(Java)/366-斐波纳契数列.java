class Solution {
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    public int fibonacci(int n) {
        // write your code here
        int a = 0, b = 1;
    	for (int i=2; i<n; i+=2) {
    		a += b;
    		b += a; 
    	}
    	return (n&1) == 1 ? a : b;
    }
}

