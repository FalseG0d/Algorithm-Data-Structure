public class Solution {
    public ArrayList<Integer> solve(ArrayList<Integer> A) {
        int N=A.size();
        PriorityQueue<Integer>pq=new PriorityQueue<Integer>();

        for(int i=0;i<N;i++){
            int temp=A.get(i);

            pq.add(temp*temp);
        }

        ArrayList<Integer>res=new ArrayList<Integer>();

        while(!pq.isEmpty()){
            int temp=pq.peek();
            pq.poll();

            res.add(temp);
        }

        return res;
    }
}