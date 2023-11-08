class Solution {
public:
    int strStr(string haystack, string needle) {
        int beg = 0;
        int end = needle.length() - 1;
        int key = 0;
        int chk = 0;

        for(int i=0;i<=end;i++) {
            key += needle[i];
        }

        for(int i=0;i<=end;i++) {
            chk += haystack[i];
        }

        int N = haystack.size();

        while(end < N) {
            // cout<<haystack.substr(beg, end - beg + 1)<<" "<<key<<" "<<chk<<"\n";
            if(chk == key) {
                if(haystack.substr(beg, end - beg + 1) == needle) return beg;
            }

            chk -= haystack[beg++];
            chk += haystack[++end];
        }

        return -1;
    }
};