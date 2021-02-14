#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallestToLeft(int arr[],int n){
    vector<int>res;
    stack<int>s;

    for(int i=0;i<n;i++){
        if(s.empty()){
            res.push_back(-1);
        }else{
            while(!s.empty()){
                if(arr[s.top()]<arr[i])
                    break;
                s.pop();
            }
            if(s.empty()) res.push_back(-1);
            else res.push_back(s.top());
        }
        s.push(i);
    }
    return res;
}

vector<int> nearestSmallestToRight(int arr[],int n){
    vector<int>res;
    stack<int>s;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            res.push_back(n);
        }else{
            while(!s.empty()){
                if(arr[s.top()]<arr[i])
                    break;
                s.pop();
            }
            if(s.empty()) res.push_back(n);
            else res.push_back(s.top());
        }
        s.push(i);
    }
    return res;
}

int maxHistoRec(int arr[],int n){
    int maxArea=0;
    vector<int>minLeft=nearestSmallestToLeft(arr,n);
    vector<int>minRight=nearestSmallestToRight(arr,n);

    for(int i=0;i<n;i++){
        maxArea=max(maxArea,(minRight[n-1-i]-minLeft[i]-1)*arr[i]);
    }

    return maxArea;
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
    
    cout<<maxHistoRec(arr,n);
    }
    
    return 0;
}
