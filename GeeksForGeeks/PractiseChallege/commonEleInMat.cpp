#include <bits/stdc++.h>
using namespace std;

void commonElements(int arr[4][5]){
    map<int,int>mp;
    int m=4,n=5;

    for(int i=0;i<n;i++){
        mp[arr[0][i]]=1;
    }

    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(mp[arr[i][j]]==i){
                mp[arr[i][j]]=i+1;
            }
            if(mp[arr[i][j]]==m-1){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

// Driver code
int main()
{
    int mat[4][5] = { 
        {1, 2, 1, 4, 8}, 
        {3, 7, 8, 5, 1}, 
        {8, 7, 7, 3, 1}, 
        {8, 1, 2, 7, 9}, 
    }; 
    
    commonElements(mat);
    return 0;
}