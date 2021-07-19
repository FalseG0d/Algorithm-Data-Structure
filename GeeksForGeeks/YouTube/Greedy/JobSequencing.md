# Job Sequencing Problem

**Problem Statement:** Given an array of Jobs where every job has a deadline and associated profit if the Job is finished before the deadline. It is also given that every job takes single unity of time, so the minum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

**Code**

```
#include <bits/stdc++.h>
using namespace std;

struct Job{
    char jobId;
    int deadline;
    int profit;

    Job(){
        jobId='N';
        deadline=0;
        profit=0;
    }

    void set(char j,int d,int p){
        jobId=j;
        deadline=d;
        profit=p;
    }
};

bool comparator(struct Job j1,struct Job j2){
    return j1.profit>j2.profit;
}

int main() {
    int n;
    cin>>n;

    struct Job*jobs=new struct Job[n];
    char jId;
    int deadline,profit;

    for(int i=0;i<n;i++){
        cin>>jId>>deadline>>profit;

        jobs[i].set(jId,deadline,profit);
    }

    sort(jobs,jobs+n,comparator);

    // for(int i=0;i<n;i++)cout<<jobs[i].jobId<<" "<<jobs[i].deadline<<" "<<jobs[i].profit<<"\n";

    struct Job temp;temp.set('N',0,0);

    struct Job*schedule=new struct Job[n]{temp};

    // for(int i=0;i<n;i++)cout<<schedule[i].jobId<<" "<<schedule[i].deadline<<" "<<schedule[i].profit<<"\n";

    for(int i=0;i<n;i++){
        int slot=jobs[i].deadline-1;

        while(jobs[i].deadline>=slot && slot>=0){
            if(schedule[slot].jobId=='N'){
                schedule[slot]=jobs[i];
                break;
                }
            else slot--;
        }
    }

    int res=0;

    for(int i=0;i<n;i++){
        // cout<<schedule[i].jobId<<" "<<schedule[i].deadline<<" "<<schedule[i].profit<<"\n";
        if(schedule[i].jobId!='N'){
            cout<<schedule[i].jobId<<"->";
            res+=schedule[i].profit;
        }
        }cout<<"NULL\n"<<res;

    return 0;
}
```