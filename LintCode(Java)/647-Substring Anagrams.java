import java.util.ArrayList;
import java.util.List;

public class Solution {
    /**
     * @param s a string
     * @param p a non-empty string
     * @return a list of index
     */
    public List<Integer> findAnagrams(String s, String p) {
        // Write your code here
    	ArrayList<Integer> list = new ArrayList<>();
    	int lenS = s.length(), lenP = p.length();
    	if (lenS < lenP) {
    		return list;
    	}
    	int[] cntS = new int[26];
    	int[] cntP = new int[26];
    	for (int i=0; i<lenP; ++i) {
    		++cntP[p.charAt(i) - 'a'];
    		++cntS[s.charAt(i) - 'a'];
    	}
    	if (check(cntS, cntP) == true) {
    		list.add(0);
    	}
    	for (int i=1; i<=lenS-lenP; ++i) {
    		--cntS[s.charAt(i-1) - 'a'];
    		++cntS[s.charAt(i-1+lenP) - 'a'];
    		if (check(cntS, cntP) == true) {
    			list.add(i);
    		}
    	}
    	return list;
    }
    private boolean check(int[] cntS, int[] cntP) {
    	for (int i=0; i<26; ++i) {
    		if (cntS[i] != cntP[i]) {
    			return false;
    		}
    	}
    	return true;
    }
}