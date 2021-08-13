int Solution::solve(int items, int circle_Size, int start_pos) {
    return (start_pos + items - 1) % circle_Size;
}