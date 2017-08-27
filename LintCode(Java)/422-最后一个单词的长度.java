public class Solution {
    /**
     * @param s A string
     * @return the length of last word
     */
    public int lengthOfLastWord(String s) {
        // Write your code here
        String[] words = s.split(" ");
    	int n = words.length;
    	return words[n-1].length();
    }
}