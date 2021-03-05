#include <iostream>
using namespace std;

int countOcc(int arr[],int n,int ele){
    int res;
    int firstOcc=-1,lastOcc=-1;
    int low=0,high=n;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]<ele)low=mid+1;
        else if(arr[mid]>ele)high=mid-1;
        else{
            firstOcc=mid;
            high=mid-1;
        }
    }

    low=0,high=n;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]<ele)high=mid-1;
        else if(arr[mid]>ele)low=mid+1;
        else{
            lastOcc=mid;
            low=mid+1;
        }
    }

    cout<<firstOcc<<"\n"<<lastOcc<<"\n";
    
    return lastOcc-firstOcc;
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int *arr=new int[n];

        for(int i=0;i<n;i++)cin>>arr[i];

        int ele;
        cin>>ele;
        cout<<countOcc(arr,n,ele);
	}
	
	return 0;
}