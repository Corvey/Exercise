public class Solution {
    /**
     * @param s a string
     * @param t a string
     * @return true if the characters in s can be replaced to get t or false
     */
    public boolean isIsomorphic(String s, String t) {
        // Write your code here
        int[] map = new int[128];
    	boolean[] isMapped = new boolean[128];
    	char[] charsetS = s.toCharArray();
    	char[] charsetT = t.toCharArray();
    	int n = charsetS.length;
    	for (int i=0; i<128; map[i++] = -1);
    	for (int i=0; i<n; ++i) {
    		if (map[charsetS[i]] == -1) {
    			if (isMapped[charsetT[i]] == false) {
    				map[charsetS[i]] = charsetT[i];
    				isMapped[charsetT[i]] = true;
    			} else {
    				return false;
    			}
    		} else if (map[charsetS[i]] != charsetT[i]) {
    			return false;
    		}
    	}
    	return true;
    }
}