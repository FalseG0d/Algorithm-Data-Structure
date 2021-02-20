#include <bits/stdc++.h>
using namespace std;

string check(string str,string res){
    if(str.length()>res.length()){
        return str;
    }else{
        return res;
    }
}

string longestPalindrome(string s){
    string str,rstr;
    str=rstr="";
    string res;
    int p=0,q=0;
    
    for(int i=0;i<s.length();i++){
        str=str+s[i];
        rstr=s[i]+rstr;
        
        if(str==rstr){
            res=check(str,res);
        }else{
            if(p==0){
                i=++q;
                str=rstr="";
                
            }else{
                
            }
        }
        cout<<res<<" ";
    }cout<<"\n";
    
    return res;
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    string s;
	    cin>>s;
	    cout<<longestPalindrome(s)<<"\n";
	}
	
	return 0;
}