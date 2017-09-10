class Solution {
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    public int[] mergeSortedArray(int[] A, int[] B) {
        // Write your code here
        int n1 = A.length, n2 = B.length;
    	int[] ret = new int[n1+n2];
    	int p1, p2, p;
    	for (p = p1 = p2 = 0; p1 < n1 && p2 < n2; ++p) {
    		ret[p] = A[p1] < B[p2] ? A[p1++] : B[p2++];
    	}
    	for (; p1 < n1; ret[p++] = A[p1++]);
    	for (; p2 < n2; ret[p++] = B[p2++]);
    	return ret;
    }
}