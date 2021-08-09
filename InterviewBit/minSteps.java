public class Solution {
    public int countTwo(int x,int y,int dest_X,int dest_Y){
        int dir_X=-1;
        int dir_Y=-1;

        if(dest_X > x) dir_X=1;
        if(dest_Y > y) dir_Y=1;

        int countX=0;
        int countY=0;

        while(dest_X!=x){
            x+=dir_X;
            countX+=1;
            }
        while(dest_Y!=y){
            y+=dir_Y;
            countY+=1;
            }

        // System.out.print(countX+":"+countY+"\t");

        return countX>countY?countX:countY;
    }
    public int coverPoints(ArrayList<Integer> A, ArrayList<Integer> B) {
        if(A.size() == 0) return 0;

        int N=A.size();
        int count=0;

        for(int i=1;i<N;i++){
            int x=A.get(i-1);
            int y=B.get(i-1);

            int dest_X=A.get(i);
            int dest_Y=B.get(i);

            count+=countTwo(x,y,dest_X,dest_Y);
        }

        return count;
    }
}