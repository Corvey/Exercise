public class Solution {
    /**
     * @param A: a array of integers
     * @return : return an integer
     */
    public int removeDuplicates(int[] nums) {
        // write your code here
        int n = nums.length, l, r;
    	l = 0;
    	for (int i=0; i<n; ++l, i=r+1) {
    		r = i;
    		for (; r<n-1 && nums[r+1] == nums[i]; ++r);
    		if (l < r) {
    			nums[l] = nums[i];
    		}
    	}
    	return l;
    }
}