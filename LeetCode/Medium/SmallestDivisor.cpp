int smallestDivisor(vector<int> &arr, int limit) {
  // Write your code here.
  int N = arr.size();

  int beg = 1;
  int end = 1;

  int res = -1;

  for(int ele: arr) end = max(ele, end);

  while (beg <= end) {
	  int mid = beg + (end - beg) / 2;
	  long long sum = 0;

	  for(int ele: arr) {
		  int curr = ele / mid;
		  if(ele % mid > 0) curr++;

		  sum += curr;
	  }

	//   cout<<mid<<" "<<sum<<"\n";

	  if(sum - limit <= 0L) {
		  res = mid;
		  end = mid-1;
	  } else {
		  beg = mid+1;
	  }
  }

  return res;
}