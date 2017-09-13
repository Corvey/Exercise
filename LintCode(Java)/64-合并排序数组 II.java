class Solution {
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    public void mergeSortedArray(int[] A, int m, int[] B, int n) {
        // write your code here
    	int pA, pB, p;
    	for (pA = m-1, pB = n-1, p = m+n-1; pA >= 0 && pB >= 0; ) {
    		A[p--] = A[pA] > B[pB] ? A[pA--] : B[pB--];
    	}
    	for (; pB >= 0; A[p--] = B[pB--]);
    }
}