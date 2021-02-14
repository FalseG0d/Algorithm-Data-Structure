#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(int arr[],int n){
    vector<int>res;

    for(int i=n-1;i>=0;i--){
        int temp=1;
        for(int j=i;j>=0;j--){
            if(arr[j]<arr[i]){
                temp++;
            }
        }
        res.push_back(temp);
    }

    return res;
}
int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    vector<int> res=stockSpan(arr,n);

    for(auto itr=res.end();itr!=res.begin();){
        --itr;
        cout<<*itr<<" ";
    }cout<<"\n";
    }
    
    return 0;
}
