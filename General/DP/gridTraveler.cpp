#include <bits/stdc++.h>
using namespace std;

int arr[19][19];

void gridTravel(){
    for(int i=0;i<18;i++){
        arr[i][17]=arr[17][i]=1;
    }
    for(int i=0;i<19;i++){
        arr[i][18]=arr[18][i]=0;
    }

    for(int i=16;i>=0;i--){
        for(int j=16;j>=0;j--){
            arr[i][j]=arr[i+1][j]+arr[i][j+1];
        }
    }

    arr[17][17]=1;
}

int main(){
    int p,q;

    gridTravel();
  
    int t;
    cin>>t;

    while(t--){
        cin>>p>>q;
        cout<<arr[18-p][18-q]<<"\n";
    }

    return 0;
}