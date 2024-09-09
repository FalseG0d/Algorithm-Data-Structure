int lowerBound(vector<int> arr, int N, int x) {
	// Write your code here
	int beg = 0;
	int end = N-1;

	int res = -1;

	while (beg <= end) {
		int mid = beg + (end - beg) / 2;

		if(arr[mid] >= x) {
			res = mid;
			end = mid-1;
		} else {
			beg = mid+1;
		}
	}

	if(res == -1) return N;
	else return res;
}
