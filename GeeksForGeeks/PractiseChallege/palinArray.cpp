// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends


/*Complete the function below*/
bool isPalin(int x){
    int temp=x;
    int s=0;
    
    while(x>0){
        int digit=x%10;
        x/=10;
        s*=10;
        s+=digit;
    }
    
    if(s==temp){
        return true;
    }else{
        return false;
    }
}

int PalinArray(int a[], int n)
{  
    //add code here.
    for(int i=0;i<n;i++){
        if(!isPalin(a[i])){
            return 0;
        }
    }
    
    return 1;
}