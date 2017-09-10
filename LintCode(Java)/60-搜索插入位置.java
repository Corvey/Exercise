public class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
    public int searchInsert(int[] A, int target) {
        // write your code here
        int n = A.length, l, r, mid;
    	l = 0; r = n-1;
    	while (l <= r) {
    		mid = l + (r - l >> 1);
    		if (target <= A[mid]) {
    			r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	return l;
    }
}
