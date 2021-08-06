#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="";
    char ch;
    
    while(cin>>ch){
        if(ch) str+=ch;
    }
    
    // cout<<str<<"\n";
    
    stack<char>st;
    
    for(int i=0;str[i]!='\0';i++){
        if(str[i] == ')'){
            if(st.top()=='('){
                cout<<"true";
                return 0;
            }
            
            while(st.top()!='('){
                st.pop();
            }st.pop();
        }
        else st.push(str[i]);
    }
    
    cout<<"false";
    return 0;
}