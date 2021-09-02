class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int N = arr.size();
        
        int beg = 0;
        int end = N - 1;
        
        int res = -1;
        
        while(beg <= end){
            int mid = beg + (end - beg) / 2;
            
            if(mid  < N - 1 && arr[mid] < arr[mid + 1]) beg = mid + 1;
            else if(mid > 0 && arr[mid] < arr[mid - 1]) end = mid - 1;
            else{
                res = mid;
                break;
            }
        }
        
        return res;
    }
};