class Solution {
    /**
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    ArrayList<String> longestWords(String[] dictionary) {
        // write your code here
    	int longestNum = 0, len;
    	ArrayList<String> list = new ArrayList<>();
    	for (String str : dictionary) {
    		len = str.length();
    		if (len < longestNum) {
    			continue;
    		} else {
    			if (len > longestNum) {
    				list.clear();
    				longestNum = len;
    			}
    			list.add(str);
    		}
    	}
    	return list;
    }
};