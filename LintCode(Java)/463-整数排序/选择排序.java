public void selectionSort(int[] A) {
	int n = A.length, minPos, temp;
	for (int i=1; i<n-1; ++i) {
		minPos = i;
		for (int j=i+1; j<n; ++j) {
			if (A[j] < A[minPos]) {
				minPos = j;
			}
		}
		if (minPos != i) {
			temp = A[i]; A[i] = A[minPos]; A[minPos] = temp;
		}
	}
}