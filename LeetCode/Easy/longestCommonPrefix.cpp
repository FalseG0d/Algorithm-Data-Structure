class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        if(strs.size()==1)return strs[0];
        
        int maxLen=INT_MAX;
        string res="";
        
        for(string s:strs)
            maxLen=s.length()<maxLen?s.length():maxLen;
        
        for(int itr=0;itr<maxLen;itr++){
            bool flag=true;
            for(int i=0;i<strs.size()-1;i++){
                if(strs[i][itr]!=strs[i+1][itr])return strs[i].substr(0,itr);
                else {
                    if(flag){
                        res+=strs[i][itr];
                        flag=!flag;
                        }
                }
            }
            // cout<<res<<"\n";
        }
        
        return res;
    }
};