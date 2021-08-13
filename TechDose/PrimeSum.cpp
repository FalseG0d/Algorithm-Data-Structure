vector<int> Solution::primesum(int A) {
    bool*prime=new bool[A+1];
    for(int i=0;i<A+1;i++) prime[i]=true;

    for(int i=2;i<A+1;i++){
        if(prime[i]){
            for(int j=2;j*i<A+1;j++) prime[j*i]=false;
        }
    }

    // for(int i=2;i<A+1;i++) cout<<i<<"\t";
    // cout<<"\n";
    // for(int i=2;i<A+1;i++) cout<<prime[i]<<"\t";
    
    vector<int>res;

    for(int i=2;i<=(A+1)/2;i++){
        if(prime[i] && prime[A-i]){
            res.push_back(i);
            res.push_back(A-i);

            break;
        }
    }

    return res;
}