int Solution::solve(int A, int B) {
    int move_right=8-B;
    int move_left=B-1;
    int move_up=A-1;
    int move_down=8-A;

    return min(move_up,move_left)+min(move_up,move_right)+min(move_down,move_left)+min(move_down,move_right);
}