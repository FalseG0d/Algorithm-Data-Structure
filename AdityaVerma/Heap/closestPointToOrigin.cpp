#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>>pi;

pair<int,int> printFreqSort(pair<int,int>*pp,int n){
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    int dist;

    for(int i=0;i<n;i++){
        dist=pp[i].first*pp[i].first+pp[i].second*pp[i].second;

        pq.push({dist,{pp[i].first,pp[i].second}});
    }

    return pq.top().second;
}

int main() {
    int n;
    cin>>n;

    pair<int,int>*pp=new pair<int,int>[n];

    for(int i=0;i<n;i++)cin>>pp[i].first>>pp[i].second;

    pair<int,int>op=printFreqSort(pp,n);

    cout<<"{"<<op.first<<","<<op.second<<"}";

    return 0;
}
