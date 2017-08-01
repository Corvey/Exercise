class Solution {
    /*
     * param a: The first integer
     * param b: The second integer
     * return: The sum of a and b
     */
    public int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int ans = a ^ b;
        int carry = a & b;
        int temp;
        while (carry != 0) {
        	temp = ans;
        	carry <<= 1;
        	ans ^= carry;
        	carry &= temp;
        }
        return ans;
    }
};