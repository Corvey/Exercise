public void selectionSort(int[] A) {
	int n = A.length, maxPos, minPos, temp;
	for (int l=0, r=n-1; l<r; ++l, --r) {
		minPos = maxPos = l;
		for (int i=l+1; i<=r; ++i) {
			if (A[i] < A[minPos]) {
				minPos = i;
			}
			if (A[i] > A[maxPos]) {
				maxPos = i;
			}
		}
		temp = A[l]; A[l] = A[minPos]; A[minPos] = temp;
		if (maxPos == l) {
			maxPos = minPos;
		}
		temp = A[r]; A[r] = A[maxPos]; A[maxPos] = temp;
	}
}