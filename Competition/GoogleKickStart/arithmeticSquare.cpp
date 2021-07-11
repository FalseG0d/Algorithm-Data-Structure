#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;

    int itr=1;

    while(t--){
        int arr[3][3];

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1&&j==1)continue;
                else cin>>arr[i][j];
            }
        }

        map<int,int>mp;
        for(int i=0;i<3;i++){
            mp[arr[i][0]+arr[2-i][2]]++;
        }

        mp[arr[0][1]+arr[2][1]]++;
        int val=INT_MIN;
        for(auto itr=mp.begin();itr!=mp.end();++itr){
            if(itr->second>val){
                arr[1][1]=(itr->first)/2;
                val=itr->second;
                }
        }

        int res=0;
        for(int i=0;i<3;i++){
            if(arr[i][0]+arr[2-i][2]==2*arr[1][1])res++;
        }

        if(arr[0][1]+arr[2][1]==2*arr[1][1])res++;

        if(arr[0][0]+arr[0][2]==2*arr[0][1])res++;
        if(arr[0][0]+arr[2][0]==2*arr[1][0])res++;
        if(arr[2][0]+arr[2][2]==2*arr[2][1])res++;
        if(arr[0][2]+arr[2][2]==2*arr[1][2])res++;


        cout<<"Case #"<<itr<<": "<<res<<"\n";
        itr++;
    }

    return 0;
}
