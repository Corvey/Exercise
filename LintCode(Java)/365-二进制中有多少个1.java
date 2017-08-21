public class Solution {
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    public int countOnes(int num) {
        // write your code here
        if (num >= 0) {
    		int ans = 0;
    		for (; num != 0; ans += num & 1, num >>= 1);
    		return ans;
    	} else {
    		return 32 - countOnes(~num);
    	}
    }
};