#include <bits/stdc++.h>
using namespace std;

int n;
int *arr;
vector<int>ans;

bool howSum(int ele){
    if(ele<0){
        return false;
    }
    if(ele==0){
        return true;
    }

    for(int i=0;i<n;i++){
        if(howSum(ele-arr[i])){
            ans.push_back(arr[i]);
            return true;
        }
    }

    return false;
}

int main(){
    int ele;
    cin>>ele>>n;

    arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    howSum(ele);

    for(auto itr=ans.begin();itr!=ans.end();++itr){
        cout<<*itr<<" ";
    }

    return 0;
}