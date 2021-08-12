public class Solution {
    public ArrayList<Integer> plusOne(ArrayList<Integer> A) {
        int N = A.size();

        for(int j = 0; j < N; j++){
            if(A.get(j) == 0){
                A.remove(j);
                j--;
                N--;
                }
            else break;
        }
        
        N = A.size();
        int carry = 1;

        if(N == 0){
            A.add(carry);
            return A;
        }
        

        for(int i = N-1; i >= 0; i--){
            int temp = A.get(i);
            temp += carry;

            carry = temp/10;
            temp %= 10;

            A.set(i, temp);

            if(carry == 0) break;
        }

        if(carry > 0){
            A.add(0, carry);
        }

        return A;
    }
}
