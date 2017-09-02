public class Solution {
    /**
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    public int majorityNumber(ArrayList<Integer> nums) {
        // write your code
    	int ans = 0, cnt = 0;
    	for (int x : nums) {
    		if (cnt == 0) {
    			ans = x;
    			cnt = 1;
    		} else if (ans == x) {
    			cnt += 1;
    		} else {
    			cnt -= 1;
    		}
    	}
    	return ans;
    }
}