#include <iostream>
#include <vector>
using namespace std;

void print(int**board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<board[i][j]<<" ";
        cout<<"\n";
    }cout<<"\n";
}

void knightTour(int**board,int row,int col,int index,int n){
    if(row < 0 || col < 0 || row>=n || col >= n) return;
    if(board[row][col] > 0) return;

    board[row][col]=index;

    if(index == n*n){
        print(board,n);
        board[row][col]=0;
        return;
        }

    knightTour(board,row-2,col+1,index+1,n);
    knightTour(board,row-1,col+2,index+1,n);
    knightTour(board,row+1,col+2,index+1,n);
    knightTour(board,row+2,col+1,index+1,n);

    knightTour(board,row+2,col-1,index+1,n);
    knightTour(board,row+1,col-2,index+1,n);
    knightTour(board,row-1,col-2,index+1,n);
    knightTour(board,row-2,col-1,index+1,n);

    board[row][col]=0;
}

int main() {
    int n;
    cin>>n;
    
    int row,col;
    cin>>row>>col;

    int**board=new int*[n];
    for(int i=0;i<n;i++) board[i]=new int[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) board[i][j]=0;
    }

    knightTour(board,row,col,1,n);

    return 0;
}
