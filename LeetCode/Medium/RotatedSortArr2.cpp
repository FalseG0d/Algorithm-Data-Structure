bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    // Write your code here.
    int beg = 0;
    int end = arr.size() - 1;

    while (beg <= end) {
        int mid = beg + (end -  beg) / 2;

        if(arr[mid] == k) return true;

        if (arr[mid] == arr[beg] && arr[beg] == arr[end]) {
            beg++;
            end--;
        } else if (arr[mid] >= arr[beg]) {
          // First part of the Array is sorted

          if (k >= arr[beg] && k <= arr[mid]) {
            // Binary Search in First Part
            if (k == arr[mid])
              return true;

            end = mid;
          } else {
            // Rotated Binary Search in Second Part
            beg = mid + 1;
          }
        } else {
          // Second part of the Array is sorted

          if (k >= arr[mid] && k <= arr[end]) {
            // Binary Search in Second Part
            if (k == arr[mid])
              return true;

            beg = mid;
          } else {
            // Rotated Binary Search in First Part
            end = mid - 1;
          }
        }
    }

    return false;
}
