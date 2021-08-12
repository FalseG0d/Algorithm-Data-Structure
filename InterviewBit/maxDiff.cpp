int Solution::maxArr(vector<int> &A) {
    int n=A.size();

    int max_1=INT_MIN;
    int max_2=INT_MIN;

    int min_1=INT_MAX;
    int min_2=INT_MAX;

    for(int i=0;i<n;i++){
        int temp = A[i];
        max_1 = max(max_1, temp + i);
        max_2 = max(max_2, i -temp);

        min_1 = min(min_1, temp + i);
        min_2 = min(min_2, i - temp);
    }

    return max(max_1 - min_1, max_2 - min_2);
}