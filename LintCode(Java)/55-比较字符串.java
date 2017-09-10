public class Solution {
    /**
     * @param A : A string includes Upper Case letters
     * @param B : A string includes Upper Case letter
     * @return :  if string A contains all of the characters in B return true else return false
     */
    public boolean compareStrings(String A, String B) {
        // write your code here
    	int[] cntA = new int[26];
    	int[] cntB = new int[26];
    	char ch;
    	for (int i=0; i<A.length(); ++i) {
    		ch = A.charAt(i);
    		++cntA[ch-'A'];
    	}
    	for (int i=0; i<B.length(); ++i) {
    		ch = B.charAt(i);
    		++cntB[ch-'A'];
    	}
    	for (int i=0; i<26; ++i) {
    		if (cntB[i] != 0 && cntA[i] < cntB[i]) {
    			return false;
    		}
    	}
    	return true;
    }
}