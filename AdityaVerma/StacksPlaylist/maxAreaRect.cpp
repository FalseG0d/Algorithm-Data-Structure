// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
vector<int> nearestSmallestToLeft(int arr[],int n){
    vector<int>res;
    stack<int>s;

    for(int i=0;i<n;i++){
        if(s.empty()){
            res.push_back(-1);
        }else{
            while(!s.empty()){
                if(arr[s.top()]<arr[i])
                    break;
                s.pop();
            }
            if(s.empty()) res.push_back(-1);
            else res.push_back(s.top());
        }
        s.push(i);
    }
    return res;
}

vector<int> nearestSmallestToRight(int arr[],int n){
    vector<int>res;
    stack<int>s;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            res.push_back(n);
        }else{
            while(!s.empty()){
                if(arr[s.top()]<arr[i])
                    break;
                s.pop();
            }
            if(s.empty()) res.push_back(n);
            else res.push_back(s.top());
        }
        s.push(i);
    }
    return res;
}

int maxHistoRec(int arr[],int n){
    int maxArea=0;
    vector<int>minLeft=nearestSmallestToLeft(arr,n);
    vector<int>minRight=nearestSmallestToRight(arr,n);

    for(int i=0;i<n;i++){
        maxArea=max(maxArea,(minRight[n-1-i]-minLeft[i]-1)*arr[i]);
        // cout<<maxArea<<"\n";
    }

    return maxArea;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int maxA=0;
    int*temp=new int[m]{0};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[j]=temp[j]*M[i][j]+M[i][j];
        }
        maxA=max(maxHistoRec(temp,m),maxA);
        // cout<<maxHistoRec(M[i],m)<<"\n";
    }
    
    return maxA;
}
