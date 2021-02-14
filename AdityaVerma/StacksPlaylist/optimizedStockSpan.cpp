#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(int arr[],int n){
    vector<int>res;
    stack<int>s;
    
    for(int i=0;i<n;i++){
        while(!s.empty()){
            if(arr[s.top()]>arr[i])break;
            s.pop();
        }
        if(s.empty())res.push_back(1);
        else res.push_back(i-s.top());
        s.push(i);
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

    for(auto itr=res.begin();itr!=res.end();++itr){
        // --itr;
        cout<<*itr<<" ";
    }cout<<"\n";
    }
    
    return 0;
}
