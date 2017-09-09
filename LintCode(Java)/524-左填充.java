public class StringUtils {
    /**
     * @param originalStr the string we want to append to with spaces
     * @param size the target length of the string
     * @return a string
     */
    static public String leftPad(String originalStr, int size) {
        // Write your code here
        return leftPad(originalStr, size, ' ');
    }

    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static public String leftPad(String originalStr, int size, char padChar) {
        // Write your code here
    	int len = originalStr.length();
    	if (len < size) {
    		StringBuilder sb = new StringBuilder();
    		for (; len < size; sb.append(padChar), ++len);
    		sb.append(originalStr);
    		return sb.toString();
    	}
    	return originalStr;
    }
}