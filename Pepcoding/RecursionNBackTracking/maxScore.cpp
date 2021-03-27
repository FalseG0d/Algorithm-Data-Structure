#include<bits/stdc++.h>
using namespace std;

int n;
map<char,int>mp;
int score[26];
int maxScore=INT_MIN;

void print(set<string>s){
    map<char,int>temp=mp;
    int tempScore=0;
    for(auto itr=s.begin();itr!=s.end();++itr){
        for(char ch:*itr){
            if(temp[ch]>0){
                temp[ch]--;
                tempScore+=score[ch-'a'];
                }else{
                    return;
                }
        }
    }
    maxScore=max(maxScore,tempScore);
}

void stringSubSets(string str[],int pos,set<string>s){
    if(pos==n){
        print(s);
        return;
        }

    s.insert(str[pos]);
    stringSubSets(str,pos+1,s);
    s.erase(str[pos]);
    stringSubSets(str,pos+1,s);
}

int main(){
    cin>>n;
    string*str=new string[n];
    for(int i=0;i<n;i++)cin>>str[i];

    int m;
    cin>>m;

    char temp;
    for(int i=0;i<m;i++){
        cin>>temp;
        mp[temp]++;
    }

    for(int i=0;i<26;i++)cin>>score[i];
    
    set<string>s;

    stringSubSets(str,0,s);
    
    cout<<maxScore;
    return 0;
}