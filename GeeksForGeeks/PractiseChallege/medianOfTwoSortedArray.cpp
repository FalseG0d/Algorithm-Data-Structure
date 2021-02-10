#include <bits/stdc++.h>
using namespace std;

int mergedMedian(vector<int>v1,vector<int>v2){
    vector<int> arr(v1.size()+v2.size());

    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),arr.begin());

    sort(arr.begin(),arr.end());
    int size=arr.size();

    if(size%2==1){
        return arr[size/2];
    }else{
        return (arr[size/2]+arr[size/2-1])/2;
    }

    return 0;
}

int main() {
    int n1,n2;
    vector<int>v1,v2;

    int t;

    cin>>t;

    while(t--){
        cin>>n1;
        int temp;
        for(int i=0;i<n1;i++){
            cin>>temp;
            v1.push_back(temp);
        }
        cin>>n2;
        for(int i=0;i<n2;i++){
            cin>>temp;
            v2.push_back(temp);
        }
    
    cout<<mergedMedian(v1,v2)<<"\n";
    }
    
    return 0;
}
