public class Solution {
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    public boolean isUgly(int num) {
        // Write your code here
        if (num <= 0) {
            return false;
        }
        for (; (num & 1) == 0; num >>= 1);
    	for (; num % 5 == 0; num /= 5);
    	for (; num % 3 == 0; num /= 3);
    	return num == 1;
    }
}