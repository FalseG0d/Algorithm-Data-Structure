int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int beg = 0;
	int end = arr.size() - 1;

	if(beg == end) return arr[beg];

	while (beg < end) {
		int mid = beg + (end - beg) / 2;

		if (arr[mid] == arr[mid - 1] || arr[mid] == arr[mid + 1]) {
			if (arr[mid] == arr[mid-1]) {
				if(mid % 2 == 0) end = mid-2;
				else beg = mid+1;
			} else {
				if(mid % 2 == 0) beg = mid+2;
				else end = mid-1;
			}
        } else {
			return arr[mid];
		}
    }

	return arr[beg];
}