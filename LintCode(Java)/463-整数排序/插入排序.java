public void insertionSort(int[] A) {
	int n = A.length, curNum, pos;
	for (int i=1; i<n; ++i) {
		curNum = A[i];
		for (pos=i; pos>0 && A[pos-1]>curNum; --pos) {
			A[pos] = A[pos-1];
		}
		A[pos] = curNum;
	}
}