public class Solution {
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    public boolean isPalindrome(String s) {
        // Write your code here
        int l, r;
    	l = 0;
    	r = s.length() - 1;
    	char a, b;
    	while (l < r) {
    		a = s.charAt(l);
    		if (!Character.isLetter(a) && !Character.isDigit(a)) {
    			++l;
    			continue;
    		}
    		b = s.charAt(r);
    		if (!Character.isLetter(b) && !Character.isDigit(b)) {
    			--r;
    			continue;
    		}
    		a = Character.toLowerCase(a);
    		b = Character.toLowerCase(b);
    		if (a != b) {
    			return false;
    		}
    		++l; --r;
    	}
    	return true;
    }
}