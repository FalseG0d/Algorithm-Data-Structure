class Solution {
public:
    int search(vector<int>& arr, int target) {
        int N=arr.size();
        
        int beg=0;
        int end=N-1;
        
        while(beg<=end){
            int mid=(beg+end)/2;
            
            if(arr[mid] == target) return mid;
                // Element Found
            else if(arr[mid] >= arr[beg]){
                // Left Sub Array is Sorted
                if(target <= arr[mid] && target >= arr[beg]) end=mid-1;
                else beg=mid+1;
            }else{
                // Right Sub Array is Sorted
                if(target <= arr[end] && target >= arr[mid]) beg=mid+1;
                else end=mid-1;
            }
        }
        
        return -1;
    }
};