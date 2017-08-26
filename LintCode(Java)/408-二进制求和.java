public class Solution {
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    public String addBinary(String a, String b) {
        // Write your code here
    	class Adder {
    		boolean isCarry = false;
    		public char add(char a, char b) {
    			if (isCarry == true) {
    				if (a == b) {
    					if (a == '0') {
    						isCarry = false;
    					}
    					return '1';
    				} else {
    					return '0';
    				}
    			} else if (a == b) {
    				if (a == '1') {
    					isCarry = true;
    				}
    				return '0';
    			} else {
    				return '1';
    			}
    		}
    	}
    	if (a.length() < b.length()) {
    		return addBinary(b, a);
    	}
    	char[] ans = new char[a.length()];
    	int p1 = a.length()-1, p2 = b.length()-1;
    	char ch1, ch2;
    	Adder adder = new Adder();
    	for (; p1 >= 0; --p1, --p2) {
    		ch1 = a.charAt(p1);
    		ch2 = p2 >= 0 ? b.charAt(p2) : '0';
    		ans[p1] = adder.add(ch1, ch2);
    	}
    	String ret = new String(ans);
    	return adder.isCarry == true ? '1' + ret : ret;
    }
}