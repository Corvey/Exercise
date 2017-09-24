/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    /**
     * @param n an integer
     * @return the number you guess
     */
    public int guessNumber(int n) {
        // Write your code here
        int l, r, mid, ans;
    	l = 1; r = n;
    	while (l <= r) {
    		mid = l + (r - l >> 1);
    		ans = guess(mid);
    		if (ans == 0) {
    			return mid;
    		} else if (ans == 1) {
    			l = mid + 1;
    		} else {
    			r = mid - 1;
    		}
    	}
    	return -1;
    }
}