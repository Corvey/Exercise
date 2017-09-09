public class Solution {
    /**
     * @param s : A string
     * @return : A string
     */
    public String reverseWords(String s) {
        // write your code
        String[] str = s.trim().split(" ");
    	StringBuilder sb = new StringBuilder();
    	for (int i=str.length-1; i>=0; --i) {
    		if ("".equals(str[i]) != true) {
    			sb.append(str[i]);
    			sb.append(' ');
    		}
    	}
    	if (sb.length() > 0) {
    		sb.deleteCharAt(sb.length()-1);
    	}
    	return sb.toString();
    }
}
