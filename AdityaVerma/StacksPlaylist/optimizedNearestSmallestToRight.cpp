#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallestToRight(int arr[],int n){
    vector<int>res;
    stack<int>s;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            res.push_back(-1);
        }else{
            while(!s.empty()){
                if(s.top()<arr[i])
                    break;
                s.pop();
            }
            if(s.empty()) res.push_back(-1);
            else res.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> res=nearestSmallestToRight(arr,n);
    
    for(auto itr=res.end();itr!=res.begin();){
        --itr;
        cout<<*itr<<" ";
    }

    return 0;
}