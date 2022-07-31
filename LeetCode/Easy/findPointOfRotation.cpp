class Solution {
public:
    int search(vector<int>& arr, int target) {
        int beg=0;
        int end=arr.size()-1; 
        int mid;
        int res=-1;
        while(beg<end){
            if((beg+end)/2==mid){mid=end;break;}
            else mid=(beg+end)/2;
            
            if(arr[mid]>arr[end])beg=mid;
            else if(arr[beg]>arr[mid])end=mid;
        }
        return 0;
    }
};