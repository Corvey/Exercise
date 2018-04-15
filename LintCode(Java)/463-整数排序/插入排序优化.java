public void insertionSort(int[] A) {
	int n = A.length, curNum, l, r, mid;
	for (int i=1; i<n; ++i) {
		curNum = A[i];
		l = 0; r = i-1;
		while (l <= r) {
			mid = l + (r - l >> 1);
			if (curNum > A[mid]) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		for (int j=i; j>l; --j) {
			A[j] = A[j-1];
		}
		A[l] = curNum;
	}
}