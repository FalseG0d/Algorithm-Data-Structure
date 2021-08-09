public class Solution {
    public int solve(ArrayList<Integer> A, int B) {
        int N=A.size();

        int maxSum=Integer.MIN_VALUE;
        for(int i=0;i<B;i++){
            int sum=0;
            for(int j=0;j<B-i;j++) sum+=A.get(N-1-j);
            for(int j=0;j<i;j++) sum+=A.get(j);

            if(sum>maxSum) maxSum=sum;
        }

        return maxSum;
    }
}