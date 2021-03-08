class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1)return 1;
        
        int res=0;
        string str="";
        map<char,int>mp;
        
        for(int i=0;s[i]!='\0';i++){
            if(mp.find(s[i])==mp.end())mp[s[i]]=i;
        }
        
        for(int i=0;s[i]!='\0';i++){
            if(str.find(s[i])==string::npos){
                str+=s[i];
            }else{
                i=mp[s[i]];
                
                res=str.length()>res?str.length():res;
                str="";
            }
            mp[s[i]]=i;
            // cout<<str<<"\n";
        }res=str.length()>res?str.length():res;
        
        return res;
    }
};