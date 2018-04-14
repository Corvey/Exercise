public void bubbleSort(int[] A) {
	int n = A.length, temp, lastSwapPos = n-1, swapPos;
	for (int i=0; i<n-1; ++i) {
		swapPos = 0;
		for (int j=0; j<lastSwapPos; ++j) {
			if (A[j] > A[j+1]) {
				temp = A[j]; A[j] = A[j+1]; A[j+1] = temp;
				swapPos = j;
			}
		}
		lastSwapPos = swapPos;
		if (lastSwapPos == 0) {
			break;
		}
	}
}