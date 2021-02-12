#include <bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterToLeft(int arr[],int n){
    vector<int>res;
    stack<int>s;

    for(int i=0;i<n;i++){
        if(s.empty()){
            res.push_back(-1);
            s.push(arr[i]);
        }else{
            while(!s.empty()){
                if(s.top()<=arr[i])
                    s.pop();
                else
                    break;
            }
            if(s.empty()){
                res.push_back(-1);
                s.push(arr[i]);
            }else{
                res.push_back(s.top());
            }

        }
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

    vector<int> res=nearestGreaterToLeft(arr,n);
    
    for(auto itr=res.begin();itr!=res.end();++itr){
        cout<<*itr<<" ";
    }

    return 0;
}