class Solution {
    /*
     * @param n: An integer
     * @return: True or false
     */
    public boolean checkPowerOf2(int n) {
        // write your code here
    	if (n <= 0) {
    		return false;
    	} else {
    		int cnt = 0;
    		for (; n != 0; cnt += n&1, n >>= 1);
    		return cnt == 1;
    	}
    }
};