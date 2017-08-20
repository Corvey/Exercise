public class Solution {
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    public boolean stringPermutation(String A, String B) {
        // Write your code here
    	char[] charsetA = A.toCharArray();
    	char[] charsetB = B.toCharArray();
    	if (charsetA.length != charsetB.length) {
    		return false;
    	} else {
    		int[] cntA = new int[256];
    		int[] cntB = new int[256];
    		int n = charsetA.length;
    		for (int i=0; i<n; ++i) {
    			++cntA[charsetA[i]];
    			++cntB[charsetB[i]];
    		}
    		for (int i=0; i<256; ++i) {
    			if (cntA[i] != cntB[i]) {
    				return false;
    			}
    		}
    		return true;
    	}
    }
}