class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        
        string word=countAndSay(n-1);
        char itr=word[0];
        
        int count=0;
        string res;
        
        for(int i=0;word[i]!='\0';i++){
            if(word[i]!=itr){
                stringstream ss;
                ss<<count;
                res+=ss.str();
                res+=itr;
                itr=word[i];
                count=0;
                i--;
            }else{
                count++;
            }
        }
        stringstream ss;
        ss<<count;
        res+=ss.str();
        res+=itr;
        
        return res;
    }
};