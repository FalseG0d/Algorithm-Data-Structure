class MinStack {
public:
    stack<long long>st;
    long long minEle = -1;

    MinStack() {
        
    }
    
    void push(int tmp) {
        long long val = tmp;
        if(st.empty()) {
            st.push(val);
            minEle = val;
        } else {
            if(val > minEle) {
                st.push(val);
            } else {
                st.push(2 * val - minEle);
                minEle = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        
        long long topEle = st.top();
        st.pop();

        if(topEle >= minEle) {
            return;
        } else {
            // Here minEle is stored
            minEle = 2 * minEle - topEle;
            return;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long topEle = st.top();

        if(topEle > minEle) {
            return topEle;
        } else {
            // Here minEle is stored
            return minEle;
        }
    }
    
    int getMin() {
        return minEle;
    }
};