public class Solution {
    public int maxArr(ArrayList<Integer> A) {
        int N = A.size();
        
        int max_1 = Integer.MIN_VALUE;
        int max_2 = Integer.MIN_VALUE;
        
        int min_1 = Integer.MAX_VALUE;
        int min_2 = Integer.MAX_VALUE;

        for(int i = 0; i < N; i++){
            int temp = A.get(i);
            max_1 = Math.max(temp + i,max_1);
            max_2 = Math.max(i - temp,max_2);

            min_1 = Math.min(temp + i,min_1);
            min_2 = Math.max(i - temp,min_2);
        }

        return Math.max(max_1 - min_1, max_2 - min_2);
    }
}