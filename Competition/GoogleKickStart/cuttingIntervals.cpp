#include <bits/stdc++.h>
using namespace std;

int findMaxIntervals(vector<int> beg, vector<int> end ,int c, int n)
{
    int endPoint = *max_element(end.begin(), end.end());
    int begPoint = *min_element(beg.begin(), beg.end());
 
    int count[endPoint - begPoint + 2]={0};
 
    for (int i = 0; i < beg.size(); i++)
    {
        count[beg[i] + 1]++;
        count[end[i]]--;
    }
 
    int max_event_tm = count[0];
 
    for (int i = begPoint; i <= endPoint; i++)
    {
        count[i] += count[i-1];
        // cout<<i<<":"<<count[i]<<"\n";
    }

    while(c--){
        int index=max_element(count,count + endPoint - begPoint + 2)-count;

        // cout<<n<<"\n";
        n=n+count[index];

        count[index]=0;
    }

    return n;
}

int main() {
    int t;
    cin>>t;

    int itr=1;

    while(t--){
        int n,c;
        cin>>n>>c;

        vector<int>beg,end;

        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            beg.push_back(temp);

            cin>>temp;
            end.push_back(temp);
        }

        int res=findMaxIntervals(beg,end,c,n);

        cout<<"Case #"<<itr<<": "<<res<<"\n";
        itr++;
    }

    return 0;
}
