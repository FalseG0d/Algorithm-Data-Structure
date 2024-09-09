int search(vector<int>& arr, int N, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int beg = 0;
    int end = N-1;

    while (beg <= end) {
        int mid = beg + (end -  beg) / 2;

        if (arr[mid] >= arr[beg]) {
            // First part of the Array is sorted

            if (k >= arr[beg] && k <= arr[mid]) {
                // Binary Search in First Part
                if(k == arr[mid]) return mid;

                end = mid;
            } else {
                // Rotated Binary Search in Second Part
                beg = mid+1;
            }
        } else {
            // Second part of the Array is sorted
            
            if (k >= arr[mid] && k <= arr[end]) {
                // Binary Search in Second Part
                if(k == arr[mid]) return mid;

                beg = mid;
            } else {
                // Rotated Binary Search in First Part
                end = mid-1;
            }
        }
    }

    return -1;
}
