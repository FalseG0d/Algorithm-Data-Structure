class Solution {
public:
    string convert(string s, int numRows) {
        int len=s.length();
        char ptrn[numRows][len];
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<len;j++)ptrn[i][j]='0';
        }
        
        vector<int>order;
        
        for(int i=0;i<numRows;i++)order.push_back(i);
        for(int i=numRows-2;i>0;i--)order.push_back(i);
        
        int chng=order.size();
        
        for(int i=0;i<len;i++){
            ptrn[order[i%chng]][i]=s[i];
        }
        
        string res="";
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<len;j++){
                if(ptrn[i][j]!='0')res+=ptrn[i][j];
            }
        }
        
        return res;
    }
};