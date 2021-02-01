#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[],int n){
    bool *order=new bool[n];

    for(int i=0;i<n-1;i++){
        if(arr[i]<arr[i+1]){
            order[i]=true;
        }else{
            order[i]=false;
        }
    }
    order[n-1]=false;
    
    int total_Profit=0;
    int cp=0,sp=0;
    for(int i=0;i<n;i++){
        if(order[i]){
            // total_Profit+=(sp-cp)
            cp=arr[i];
        }else{
            if(i==n-1||arr[i]>arr[i+1])
                sp=arr[i];
        }

        if(cp!=0&&sp!=0){
            cout<<cp<<" "<<sp<<" ";
            total_Profit+=(sp-cp);
            cp=sp=0;
        }
    }cout<<"\n";

    return total_Profit;
}

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int*arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<maxProfit(arr,n)<<"\n";
    }

    return 0;
}
