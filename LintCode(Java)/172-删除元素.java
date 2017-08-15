public class Solution {
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    public int removeElement(int[] A, int elem) {
        // write your code here
    	int n = A.length, pos;
    	for (pos = 0; pos < n && A[pos] != elem; ++pos);
    	for (int i=pos+1; i<n; ++i) {
			if (A[i] != elem) {
				A[pos++] = A[i];
			}
		}
    	return pos;
    }
}
