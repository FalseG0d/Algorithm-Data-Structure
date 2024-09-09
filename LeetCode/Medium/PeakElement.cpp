int findPeakElement(vector<int> &arr) {
    // 1 5 2 7 3 2 3 5 2
    // 0 1 2 3 4 5 6 7 8
    // Write your code here
    int beg = 0;
    int end = arr.size()-1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        
        if(mid == 0 && arr[mid] > arr[mid+1]) return mid;
        else if(mid == arr.size()-1 && arr[mid] > arr[mid-1]) return mid;
        else if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
        
        
        if(arr[mid-1] > arr[mid+1]) end = mid-1;
        else beg = mid+1;
    }

    return -1;
}
