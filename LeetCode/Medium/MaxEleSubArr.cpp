vector<int> Solution::slidingMaximum(const vector<int> &A, int K) {
    int N = A.size();
    vector<int>res;
    deque<int>deq;
    
    
    int beg = 0;
    int end = 0;
    
    while(end < K-1){
        while(!deq.empty() && A[deq.front()] < A[end]) deq.pop_front();
        while(!deq.empty() && A[deq.back()] < A[end]) deq.pop_back();
        
        deq.push_back(end);
        end++;
    }
    
    while(end < N){
        while(!deq.empty() && A[deq.front()] < A[end]) deq.pop_front();
        while(!deq.empty() && A[deq.back()] < A[end]) deq.pop_back();
        
        deq.push_back(end);
        
        res.push_back(A[deq.front()]);
        
        if(beg == deq.front()) deq.pop_front();
        
        beg++;
        end++;
    }
    
    return res;
}