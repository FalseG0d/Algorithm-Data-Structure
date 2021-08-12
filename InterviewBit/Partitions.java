public class Solution {
    public int solve(int N, ArrayList<Integer> A) {
        int check = 0;
        for(int ele:A) check+=ele;

        if(check%3 != 0) return 0;

        check/=3;

        boolean[]prefix=new boolean[N];
        boolean[]suffix=new boolean[N];

        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A.get(i);

            prefix[i] = (sum == check);
        }

        sum=0;
        for(int i=N-1;i>=0;i--){
            sum+=A.get(i);

            suffix[i] = (sum == check);
        }

        int res=0;

        for(int i=0;i<N-2;i++){
            for(int j=N-1;j>i+1;j--){
                if(prefix[i] && suffix[j]){
                    sum = 0;

                    for(int k=i+1;k<j;k++) sum+=A.get(k);

                    if(sum == check) res++;
                }
            }
        }

        return res;
    }
}