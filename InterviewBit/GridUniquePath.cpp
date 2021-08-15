int Solution::uniquePaths(int A, int B) {
    int**map=new int*[A];
    for(int i=0;i<A;i++)map[i]=new int[B];

    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++) map[i][j]=0;
    }

    for(int i=0;i<A;i++) map[i][B-1]=1;
    for(int i=0;i<B;i++) map[A-1][i]=1;

    for(int i=A-2;i>=0;i--){
        for(int j=B-2;j>=0;j--){
            map[i][j]=map[i+1][j]+map[i][j+1];
        }
    }

    return map[0][0];
}