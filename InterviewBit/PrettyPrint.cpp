vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int>>res;

    for(int i=0;i<A;i++){
        vector<int>temp;
        for(int j=0;j<A;j++) temp.push_back(max(A - i, A - j));
        for(int j=A-2;j>=0;j--) temp.push_back(max(A - i, A - j));
        res.push_back(temp);
    }
    for(int i=A-2;i>=0;i--){
        vector<int>temp;
        for(int j=0;j<A;j++) temp.push_back(max(A - i, A - j));
        for(int j=A-2;j>=0;j--) temp.push_back(max(A - i, A - j));
        res.push_back(temp);
    }

    return res;
}