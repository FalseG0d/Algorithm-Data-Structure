#include<bits/stdc++.h>
#define N 4
using namespace std;

int getFirstDiag(int i,int j){
    int check=i-j;
    
    return N-check-1;
}
int getSecondDiag(int i,int j){
    int check=i+j;
    
    return check;
}
int getCol(int i,int j){
    return j;
}

void print(vector<int>res){
    int arr[N][N]={0};
    for(int i=0;i<N;i++){
        arr[i][res[i]]=1;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)cout<<arr[i][j]<<" ";
        cout<<"\n";
    }cout<<"\n\n";
}

void nQueen(bool col[],bool diag1[],bool diag2[],int p,int q,vector<int>res){
    if(p>=N){
        print(res);
        return;
        }
    if(q>=N)return;

    int np=p;

    for(int i=0;i<N;i++){
        int colNo=getCol(p,i);
        int diag1No=getFirstDiag(p,i);
        int diag2No=getSecondDiag(p,i);

        if(col[colNo]==false&&diag1[diag1No]==false&&diag2[diag2No]==false){
            // cout<<colNo<<" "<<diag1No<<" "<<diag2No<<"\n";
            res.push_back(colNo);
            col[colNo]=diag1[diag1No]=diag2[diag2No]=true;
            nQueen(col,diag1,diag2,np+1,0,res);
            col[colNo]=diag1[diag1No]=diag2[diag2No]=false;
            res.pop_back();
            }
    }
}

int main(){
    int arr[N][N]={0};
    
    vector<int>res;

    bool col[N]={false},diag1[2*N-2]={false},diag2[2*N-2]={false};

    nQueen(col,diag1,diag2,0,0,res);

    return 0;
}