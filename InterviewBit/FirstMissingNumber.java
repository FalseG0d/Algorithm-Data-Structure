public class Solution {
    public int firstMissingPositive(ArrayList<Integer> A) {
        PriorityQueue<Integer>pq=new PriorityQueue<>();

        for(int ele:A){
            if(ele > 0) pq.add(ele);
        }

        int count=1;
        while(!pq.isEmpty()){
            if(pq.peek() != count)break;

            count++;

            pq.poll();
        }
        // System.out.println(pq);
        return count;
    }
}