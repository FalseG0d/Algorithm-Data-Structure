#include<bits/stdc++.h>
using namespace std;

set<string>s;

void lexiographic(int n){
    for(int i=1;i<=n;i++){
        int x=i;
        string temp="";

        while(x>0){
            char ch='0'+(char)(x%10);
            temp=ch+temp;
            x/=10;
        }
        
        s.insert(temp);
    }
}

int main(){
    int n;
    cin>>n;

    lexiographic(n);

    for(auto itr=s.begin();itr!=s.end();++itr)cout<<*itr<<"\n";
    return 0;
}