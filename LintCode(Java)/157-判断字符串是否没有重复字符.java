public class Solution {
    /**
     * @param str: a string
     * @return: a boolean
     */
    public boolean isUnique(String str) {
        // write your code here
        boolean[] cnt = new boolean[256];
    	for (char c : str.toCharArray()) {
    		if (cnt[c] == true) {
    			return false;
    		}
    		cnt[c] = true;
    	}
    	return true;
    }
}