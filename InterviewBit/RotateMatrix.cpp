void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n1=A.size();
    int n2=A[0].size();

    for(int i=0;i<n1;i++){
        for(int j=0;j<=i;j++){
            int temp=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temp;
        }
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2/2;j++){
            int temp=A[i][j];
            A[i][j]=A[i][n2-j-1];
            A[i][n2-j-1]=temp;
        }
    }

}