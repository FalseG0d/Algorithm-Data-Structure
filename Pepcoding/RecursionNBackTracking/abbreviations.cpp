#include<bits/stdc++.h>

using namespace std;

bool isNum(char ch){
    if(ch>='0'&&ch<='9')return true;
    else return false;
}

int getVal(char ch){
    switch(ch){
        case '0':return 0;break;
        case '1':return 1;break;
        case '2':return 2;break;
        case '3':return 3;break;
        case '4':return 4;break;
        case '5':return 5;break;
        case '6':return 6;break;
        case '7':return 7;break;
        case '8':return 8;break;
        case '9':return 9;break;
    }return -1;
}

void abreviate(string s,int pos){
    if(pos==s.length()){
        string newStr="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                int greaterOneVal=0;
                while(s[i]=='1'){
                    greaterOneVal++;
                    i++;
                    }i--;
                newStr+=(char)('0'+greaterOneVal);
            }else newStr+=s[i];
        }
        cout<<newStr<<"\n";
        return;
    }
    
    char temp=s[pos];
    abreviate(s,pos+1);
    
    s[pos]='1';
    
    abreviate(s,pos+1);
    s[pos]=temp;
}

int main(){
    string s;
    cin>>s;
    
    abreviate(s,0);

    return 0;
}