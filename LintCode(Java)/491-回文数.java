public class Solution {
    /**
     * @param num a positive number
     * @return true if it's a palindrome or false
     */
    public boolean palindromeNumber(int num) {
        // Write your code here
        int n = (int) Math.floor(Math.log10(num)) + 1;
    	int[] nums = new int[n];
    	for (int i=0; i<n; ++i) {
    		nums[i] = num % 10;
    		num /= 10;
    	}
    	for (int l=0, r=n-1; l < r; ++l, --r) {
    		if (nums[l] != nums[r]) {
    			return false;
    		}
    	}
    	return true;
    }
}