#include<iostream>
#include<vector>
using namespace std;

vector<string>getPath(int n){
    if(n==0){
        vector<string>v;
        v.push_back("");
        return v;
    }
    
    vector<string>res;
    vector<string>temp;
    
    if(n-1>=0){
        temp=getPath(n-1);
        for(string str:temp){
            res.push_back("1"+str);
        }
    }
    if(n-2>=0){
        temp=getPath(n-2);
        for(string str:temp){
            res.push_back("2"+str);
        }
    }
    if(n-3>=0){
        temp=getPath(n-3);
        for(string str:temp){
            res.push_back("3"+str);
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    
    vector<string> res=getPath(n);
    
    n=res.size();
    
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<res[i];
        if(i<n-1)cout<<", ";
    }cout<<"]";
    
    return 0;
}