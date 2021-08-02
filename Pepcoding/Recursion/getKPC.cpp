#include<iostream>
#include<vector>
using namespace std;

vector<string>getKeys(char ch){
    switch(ch){
        case '0': return {".",";"};
        case '1': return {"a","b","c"};
        case '2': return {"d","e","f"};
        case '3': return {"g","h","i"};
        case '4': return {"j","k","l"};
        case '5': return {"m","n","o"};
        case '6': return {"p","q","r","s"};
        case '7': return {"t","u"};
        case '8': return {"v","w","x"};
        case '9': return {"y","z"};
    }
    
    return {};
}

vector<string>getKPC(string str){
    if(str.length()==1){
        return getKeys(str[0]);
    }
    
    vector<string>choices=getKeys(str[0]);
    vector<string>ret=getKPC(str.substr(1));
    
    vector<string>res;
    
    for(string ch:choices){
        for(string str:ret){
            res.push_back(ch+str);
        }
    }
    
    return res;
}

int main(){
    string str;
    cin>>str;
    
    vector<string>res=getKPC(str);
    
    int n=res.size();
    
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<res[i];
        if(i<n-1) cout<<", ";
    }
    cout<<"]";
}