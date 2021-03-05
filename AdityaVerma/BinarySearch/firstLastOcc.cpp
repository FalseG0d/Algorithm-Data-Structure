#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int lastOcc(int arr[], int n, int x)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
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
        cout<<"First Occurence At "<<firstOcc(arr,n,ele);
        cout<<"\nLast Occurence At "<<lastOcc(arr,n,ele);
	}
	
	return 0;
}