#include <iostream>
using namespace std;
 
#define N 4
 
// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int arr[N][N])
{
    for(int i=0;i<N/2;i++){
        for(int j=i;j<N-i-1;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[N-1-j][i];
            arr[N-1-j][i]=arr[N-1-i][N-1-j];
            arr[N-1-i][N-1-j]=arr[j][N-1-i];
            arr[j][N-1-i]=temp;
        }
    }
}
 
// Function for print matrix
void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    printMatrix(arr);
    cout<<"\n\n";
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}