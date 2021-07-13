# Activity Selection Problem

*Problem Statement: Given 'N' activities eith their start and finish times. Select the maximum number f activities that can be performed by a single person, assuming that a person can perform only a single activity at a time.*

**Pseudo Code:**

1. Sort the activities according to their finish time.
2. Select the First Activity.
    1. Loop through the Activities:
    2. If the next activity's start time exceeds the previous's end time skip it.
    3. Else Select the activity.

**Time Complexity:** n*Log(n)

**Code**

```
#include <bits/stdc++.h>
using namespace std;

struct Activity{
    char name;
    int startTime;
    int endTime;

    void set(char n,int s,int e){
        name=n;
        startTime=s;
        endTime=e;
    }
};

bool compareActivity(Activity a1,Activity a2){
    return a1.endTime<a2.endTime;
}

int main() {
    int n;
    cin>>n;

    struct Activity*activities=new Activity[n];
    
    int s,e;
    char name;

    for(int i=0;i<n;i++){
        cin>>name;
        cin>>s>>e;

        activities[i].set(name,s,e);
    }

    // for(int i=0;i<n;i++)cout<<activities[i].name<<"\t";
    // cout<<"\n";
    // for(int i=0;i<n;i++)cout<<activities[i].startTime<<"\t";
    // cout<<"\n";
    // for(int i=0;i<n;i++)cout<<activities[i].endTime<<"\t";
    // cout<<"\n\n\n";

    sort(activities,activities+n,compareActivity);

    // for(int i=0;i<n;i++)cout<<activities[i].name<<"\t";
    // cout<<"\n";
    // for(int i=0;i<n;i++)cout<<activities[i].startTime<<"\t";
    // cout<<"\n";
    // for(int i=0;i<n;i++)cout<<activities[i].endTime<<"\t";
    // cout<<"\n";

    int prevEndTime=-1;
    for(int i=0;i<n;i++){
        if(activities[i].startTime<prevEndTime)continue;
        else{
            cout<<"A"<<activities[i].name<<" -> ";
            prevEndTime=activities[i].endTime;
        }
    }

    cout<<"0";

    return 0;
}
```