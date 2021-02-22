#include <iostream>
using namespace std;

int longestPalSubstr(string str)
{
    int n = str.size();
    int maxLength = 1, start = 0;
 
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            int flag = 1;
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
    return maxLength;
}

char*nextAcceptable(int n,char*ch){
    char*no=new char[2];
    no[0]='N';
    no[1]='o';
    
    char*yes=new char[3];
    yes[0]='Y';
    yes[1]='e';
    yes[2]='s';
    
    for(int i=0;i<n;i++){
        if(ch[i]-97>n){
            return no;
        }
    }

    if(longestPalSubstr(ch)>1){
        return no;
    }

    return yes;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char*ch=new char[n];
        for(int i=0;i<n;i++)cin>>ch[i];

        char*ans=nextAcceptable(n,ch);
        if(ans[0]=='Y')cout<<"Yes";
        else cout<<"No";
    }
}
