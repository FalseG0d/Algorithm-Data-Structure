#include <bits/stdc++.h>
using namespace std;

int sumQ(queue<int> que){
    int sum=0;

    while(!que.empty()){
        sum+=que.front();
        que.pop();
    }
    
    return sum;
}

void print(queue<int> que){
    int sum=0;

    while(!que.empty()){
        cout<<que.front()<<" ";
        que.pop();
    }cout<<"\n";
}

void subArrOfSizeK(int arr[],int k,int n){
    queue<int> que;

    for(int i=0;i<n;i++){
        int sum=sumQ(que);

        if(sum+arr[i]<=k){
            que.push(arr[i]);
            sum+=arr[i];
            }
        else{
            sum-=que.front();
            que.pop();
            i--;
        }

        if(sum==k)
            print(que);
    }
}

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int*arr=new int[n];

        for(int i=0;i<n;i++)cin>>arr[i];

        int k;
        cin>>k;

        subArrOfSizeK(arr,k,n);
    }

    return 0;
}
 