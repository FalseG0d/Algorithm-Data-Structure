// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     
     int s_len = s.length();
     int x_len = x.length();
     
     for(int i=0;i<s_len;i++){
         for(int j=0;j<x_len;j++){
             if(s[i] == x[j]){
                //  cout<<s[i];
                 
                 i++;
                 
                 if(j == x_len-1) return i-j-1;
             }else{
                 break;
             }
         }
     }
     
     return -1;
}