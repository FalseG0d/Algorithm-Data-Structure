#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr1[]={1, 2, 3, -4, -1, 4};

    vector<int>neg,pos;

    for(int i=0;i<sizeof(arr1)/sizeof(int);i++){
        if(arr1[i]<0){
            neg.push_back(arr1[i]);
        }else{
            pos.push_back(arr1[i]);
        }
    }

    int p1=0,p2=0;
    vector<int> ans;
    while(p1<neg.size()||p2<pos.size()){
        if(p1<neg.size()){
            ans.push_back(neg[p1]);
            p1++;
            }
        if(p2<pos.size()){
            ans.push_back(pos[p2]);
            p2++;
        }
    }

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}
