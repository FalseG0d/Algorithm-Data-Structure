#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
    
        int res=INT_MIN;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                for(int p=i+1;p<n;p++){
                    for(int q=j+1;q<n;q++){
                        res=max(arr[p][q]-arr[i][j],res);
                    }
                }
            }
        }

        cout<<res<<"\n";

    }
    
    return 0;
}
