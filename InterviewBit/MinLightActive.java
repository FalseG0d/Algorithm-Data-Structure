public class Solution {
    public int solve(ArrayList<Integer> A, int B) {
    int c = Math.abs(1-B);
    
    int n = A.size();
    int cnt1 = 0, cnt2=0;
    int i=0;
    while(i<n) {
        if(A.get(i) == 1) {
            break;
        }
        cnt2++;
        i++;
    }
    
    if(cnt2 > c) {
        return -1;
    }
    int flag = 0;
    for( ; i<n; i++) {
        if(A.get(i) == 0) {
            cnt1++;
            if(cnt1 > 2*c) return -1;
        }
        else {
            cnt1 = 0;
            flag=1;
        }
    }
    if((2*c + 1) > n) {
        if(flag == 1) {
            return 1;
        }
        return -1;
    }
    if(n%(2*c + 1) != 0) {
        return (n  / (2*c + 1)) +1;
    }
    return (n/(2*c + 1));
}

}