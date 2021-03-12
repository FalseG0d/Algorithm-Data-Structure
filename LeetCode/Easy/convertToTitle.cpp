class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(!columnNumber) return "";
        return convertToTitle((columnNumber - 1) / 26) + (char) ((columnNumber - 1) % 26 + 'A');
    }
};