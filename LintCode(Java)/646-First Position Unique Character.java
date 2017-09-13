public class Solution {
    /**
     * @param s a string
     * @return it's index
     */
    public int firstUniqChar(String s) {
        // Write your code here
    	int[] cnt = new int[256];
    	char[] charArray = s.toCharArray();
    	for (char ch : charArray) {
    		++cnt[ch];
    	}
    	for (int i=0; i<charArray.length; ++i) {
    		if (cnt[charArray[i]] == 1) {
    			return i;
    		}
    	}
    	return -1;
    }
}