#include <bits/stdc++.h>
using namespace std;

typedef pair<float,int> pp;

int main() {
    int n;
    cin>>n;

    int*wt=new int[n];
    float*val=new float[n];

    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>wt[i];

    pp*p=new pp[n];

    for(int i=0;i<n;i++){
        p[i].first=val[i]/wt[i];
        p[i].second=wt[i];
    }

    int cap;
    cin>>cap;

    float res=0;

    sort(p,p+n,greater<pp>());

    for(int i=0;i<n;i++){
        if(cap<=0)break;

        res+=p[i].first*min(p[i].second,cap);
        cap-=p[i].second;
    }

    // for(int i=0;i<n;i++){
    //     cout<<p[i].first<<":"<<p[i].second<<'\n';
    // }

    // cout<<std::fixed<<std::setprecision(1);
    cout<<res;

    return 0;
}
