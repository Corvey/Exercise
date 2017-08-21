public class Solution {
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        // write your code here
        int row = matrix.length;
    	int l, r, mid;
    	l = 0; r = row-1;
    	while (l <= r) {
    		mid = l + (r - l >> 1);
    		if (target == matrix[mid][0]) {
    			return true;
    		} else if (target < matrix[mid][0]) {
    			r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	if (l == 0) {
    		return false;
    	}
    	int destRow = l - 1;
    	l = 0; r = matrix[destRow].length - 1;
    	while (l <= r) {
    		mid = l + (r - l >> 1);
    		if (target == matrix[destRow][mid]) {
    			return true;
    		} else if (target < matrix[destRow][mid]) {
    			r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	return false;
    }
}
