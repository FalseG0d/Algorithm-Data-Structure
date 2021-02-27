#include <bits/stdc++.h>
using namespace std;

int equalBinaryString(string s){
    int res;
    int p=0,count=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='1')count++;
        else count--;

        if(count==0){
            // cout<<(s.substr(p,i+1))<<"\n";
            res++;
            p=i+1;
        }
    }

    return res;
}

int main() {
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        // vector<string>res=equalBinaryString(s);
        cout<<equalBinaryString(s)%10<<"\n";

        // for(string ele:res){
        //     cout<<ele<<"\n";
        // }
    }
}
