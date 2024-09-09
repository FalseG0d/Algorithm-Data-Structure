int findMin(vector<int>& arr)
{
	// Write your code here.

	// 21 27 30 38 39 46 11 12 15 19
	// 0. 1. 2. 3. 4. 5. 6. 7. 8. 9

	int beg = 0;
	int end = arr.size()-1;

	int res = INT_MAX;

	while(beg <= end) {
		int mid = beg + (end - beg) / 2;

		if (beg == mid) {
			res = min(res, arr[beg]);
			beg++;
		} else if (arr[mid] > arr[beg]) {
			// First Half is Sorted

			res = min(res, arr[beg]);
			beg = mid+1;
		} else {
			// Second Half is Sorted

			res = min(res, arr[mid]);
			end = mid-1;
		}
    }

	return res;
}