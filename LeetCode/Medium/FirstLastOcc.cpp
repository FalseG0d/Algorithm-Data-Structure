pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int first = -1;
    int last = -1;

    int beg = 0;
    int end = n-1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;

        if(arr[mid] >= k) {
            if(arr[mid] == k) first = mid;
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    beg = 0;
    end = n-1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;

        if(arr[mid] <= k) {
            if(arr[mid] == k) last = mid;
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return make_pair(first, last);
}
