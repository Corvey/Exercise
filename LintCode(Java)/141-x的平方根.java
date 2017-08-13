class Solution {
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    public int sqrt(int x) {
        // write your code here
        int l, r, mid, square;
        l = 0;
        r = (x >> 1) + 1;
        if (r > 46340) {
        	r = 46340;
        }
        while (l <= r) {
        	mid = l + (r - l >> 1);
        	square = mid * mid;
        	if (x == square) {
        		return mid;
        	} else if (x < square) {
        		r = mid - 1;
        	} else {
        		l = mid + 1;
        	}
        }
        return l - 1;
    }
}