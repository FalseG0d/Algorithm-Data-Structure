class Solution {
public:
    int search(vector<int>& arr, int target) {
        int beg=0;
        int end=arr.size()-1;
        
        int mid=(beg+end)/2;
        int res=-1;
        
        while(beg<end){            
            if(arr[mid]>arr[end])beg=mid;
            else if(arr[beg]>arr[mid])end=mid;
            
            if((beg+end)/2==mid){mid=end;break;}
            else mid=(beg+end)/2;
        }
        
        beg=0;
        end=arr.size()-1;
        
        cout<<mid<<"\n";
        
        if(target>=arr[mid]&&target<=arr[end])beg=mid;
        else end=mid-1;
        
        cout<<beg<<":"<<end;
        
        while(beg<=end){
            mid=(beg+end)/2;
            
            if(arr[mid]>target)end=mid-1;
            else if(arr[mid]<target)beg=mid+1;
            else {res=mid;break;}
        }
        
        // cout<<res;
        
        return res;
    }
};