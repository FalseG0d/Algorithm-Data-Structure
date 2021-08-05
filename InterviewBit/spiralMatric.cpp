vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int top=0;
    int down=A.size()-1;
    int left=0;
    int right=A[0].size()-1;

    int dir=0;
    vector<int>res;

    while(top <= down && left <= right){
        if(dir == 0){
            for(int i=left;i<=right;i++) res.push_back(A[top][i]);
            top++;
        }
        else if(dir == 1){
            for(int i=top;i<=down;i++) res.push_back(A[i][right]);
            right--;
        }
        else if(dir == 2){
            for(int i=right;i>=left;i--) res.push_back(A[down][i]);
            down--;
        }
        else{
            for(int i=down;i>=top;i--) res.push_back(A[i][left]);
            left++;
        }
        
        dir=(dir+1)%4;
    }

    return res;
}