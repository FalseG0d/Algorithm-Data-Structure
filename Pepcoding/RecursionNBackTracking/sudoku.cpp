#include<bits/stdc++.h>
using namespace std;

int mat[9][9];

bool isValid(int p,int q,int ele){
    for(int )
}

void sudokuSolve(int p,int q){
    int np,nq;
    if(q==8){
        np=p+1;
        nq=0;
    }else{
        np=p;
        nq=q+1;
    }
    
    if(mat[p][q]!=0)sudokuSolve(np,nq);
    else{
        for(int i=1;i<10;i++){
            if(isValid(p,q,i)){
                mat[p][q]=i;
                sudokuSolve(np,nq);
                mat[p][q]=0;
            }
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>mat[i][j];
        }
    }
    
    sudokuSolve(0,0);
    
    return 0;
}