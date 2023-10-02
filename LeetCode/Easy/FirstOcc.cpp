class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();

        int hash = 0;
        int check = 0;

        for(int i=0;i<len2;i++) {
            hash += needle[i];
            check += haystack[i];
        }

        int beg = 0;
        int end = len2;

        while(end <= len1) {
            if(check == hash && needle == haystack.substr(beg, len2)) {
                return beg;
            }

            check -= haystack[beg];
            check += haystack[end];

            beg++;
            end++;
        }

        return -1;
    }
};