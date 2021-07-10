#include<iostream>
using namespace std;

int mod(int x){
    return x>0?x:-x;
}

int main(){
    int t;
    cin>>t;

    int itr=1;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        string str;
        cin>>str;
        
        cout<<"Case #"<<itr<<": ";
        
        int score=0;
        
        for(int i=0;i<=n/2-1;i++){
            if(str[i]!=str[n-1-i])score++;
        }
        
        cout<<mod(k-score);

        // cout<<k<<":"<<score;
        
        cout<<"\n";
        
        itr++;
    }
    
    return 0;
}