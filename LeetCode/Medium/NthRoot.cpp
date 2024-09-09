int NthRoot(int N, int M) {
  // Write your code here.
    if(N == 0) return 0;

    int beg = 1;
    int end = M;

    int res = -1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        long long val = pow(mid, N);

        if(val - M == 0L) {
          res = mid;
          break;
        } else if (val - M < 0L) {
          beg = mid+1;
        } else {
          end = mid-1;
        }
    }

    return res;
}