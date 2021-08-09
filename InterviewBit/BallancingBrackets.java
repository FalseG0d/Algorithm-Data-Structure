public class Solution {
    public int solve(String A) {
        Stack<Character>s=new Stack<>();

        char[]chArray=A.toCharArray();

        for(char ch:chArray){
            if(ch == '(') s.push(ch);
            else {
                if(!s.empty()) s.pop();
                else return 0;
                }
        }

        return s.empty()?1:0;
    }
}
