class Solution {
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    public double cosineSimilarity(int[] A, int[] B) {
        // write your code here
        int n = A.length;
    	double multSum, squareSumA, squareSumB;
    	multSum = squareSumA = squareSumB = 0;
    	for (int i=0; i<n; ++i) {
    		multSum += A[i] * B[i];
    		squareSumA += A[i] * A[i];
    		squareSumB += B[i] * B[i];
    	}
    	if (squareSumA == 0 || squareSumB == 0) {
    		return 2;
    	}
    	return multSum / Math.sqrt(squareSumA) / Math.sqrt(squareSumB);
    }
}
