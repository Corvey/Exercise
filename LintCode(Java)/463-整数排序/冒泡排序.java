public void bubbleSort(int[] A) {
	int n = A.length, temp;
	for (int i=0; i<n-1; ++i) {
		for (int j=0; j<n-1-i; ++j) {
			if (A[j] > A[j+1]) {
				temp = A[j]; A[j] = A[j+1]; A[j+1] = temp;
			}
		}
	}
}