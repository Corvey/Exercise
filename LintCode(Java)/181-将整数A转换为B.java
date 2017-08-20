class Solution {
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    public static int bitSwapRequired(int a, int b) {
        // write your code here
        int num = a ^ b;
    	int ans = 0;
    	if (num >= 0) {
    		for (; num != 0; ans += num & 1, num >>= 1);
    		return ans;
    	} else {
    		num = ~num;
    		for (; num != 0; ans += num & 1, num >>= 1);
    		return 32 - ans;
    	}
    }
};
