#include <bits/stdc++.h>
using namespace std;
int main() {
    int len1,len2;
    int arr1[100],arr2[100];

    cin>>len1>>len2;
    for(int i=0;i<len1;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<len2;i++){
        cin>>arr2[i];
    }

    set<int> s;

    for(int i=0;i<len1;i++){
        s.insert(arr1[i]);
    }

    for(int i=0;i<len2;i++){
        s.erase(s.find(arr2[i]));
    }

    cout<<len1-s.size();
    return 0;
}
