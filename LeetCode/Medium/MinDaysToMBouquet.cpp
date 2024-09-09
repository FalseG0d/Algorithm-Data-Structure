int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int N = arr.size();

	if(m * k > N) return -1;

	int beg = INT_MAX;
	int end = INT_MIN;

	for(int ele: arr) {
		beg = min(beg, ele);
		end = max(end, ele);
	}

	int res = -1;

	while (beg <= end) {
		int mid = beg + (end - beg) / 2;

		int pre = -1;
		int cnt = 0;
		
		for(int i=0;i<N;i++) {
			if(arr[i] - mid > 0) pre = i;
			else if(i - pre >= k) {
				cnt += (i - pre) / k;
				pre = i;
			}
		}
		
		if(cnt >= m) {
			res = mid;
			end = mid-1;
		} else {
			beg = mid+1;
		}
	}

	return res;
}