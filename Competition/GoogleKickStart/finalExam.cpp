#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;

    int itr=1;

    while(t--){
        int n;
        int m;
        cin>>n>>m;

        int*beg=new int[n];
        int*end=new int[n];

        int max_Difficulty=-1;

        for(int i=0;i<n;i++){
            cin>>beg[i]>>end[i];

            max_Difficulty=max(max_Difficulty,end[i]);
        }

        int*s=new int[m];
        for(int i=0;i<m;i++)cin>>s[i];

        int*questions=new int[max_Difficulty+1]{0};

        for(int i=0;i<n;i++){
            for(int j=beg[i];j<=end[i];j++)questions[j]=1;
        }

        cout<<"Case #"<<itr<<": ";
        itr++;

        for(int i=0;i<m;i++){
            if(s[i]<=max_Difficulty){
                int ptr=s[i];

                while(ptr>=0&&questions[ptr]==0)ptr--;
                if(ptr>=0){
                    cout<<ptr<<" ";
                    questions[ptr]=0;
                    }
                else{
                    int ptr=s[i];
                    while(ptr<=max_Difficulty&&questions[ptr]==0)ptr++;
                    
                    if(ptr<=max_Difficulty){
                        cout<<ptr<<" ";
                        questions[ptr]=0;
                        }
                    else cout<<-1<<" ";
                }
            }else{
                int ptr=max_Difficulty;

                while(ptr>=0&&questions[ptr]==0)ptr--;
                if(ptr>=0){
                    cout<<ptr<<" ";
                    questions[ptr]=0;
                    }
                else cout<<-1<<" ";
            }
        }

        cout<<"\n";
    }

    return 0;
}
