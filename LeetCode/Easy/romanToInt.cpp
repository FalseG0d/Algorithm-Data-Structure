class Solution {
public:
    int valueOf(char ch){
        int value=0;
        switch(ch){
            case 'I':value=1;break;
            case 'V':value=5;break;
            case 'X':value=10;break;
            case 'L':value=50;break;
            case 'C':value=100;break;
            case 'D':value=500;break;
            case 'M':value=1000;break;
        }
        return value;
    }
    int romanToInt(string str) {
        int res=0;
        
        for(int i=0;i<str.length();i++){
            if(i+1<str.length()){
                if(valueOf(str[i])>=valueOf(str[i+1])){
                    res=res+valueOf(str[i]);
                }else{
                    res=res+valueOf(str[i+1])-valueOf(str[i]);
                    i++;
                }
            }else{
                res+=valueOf(str[i]);
            }cout<<res<<":"<<i<<"\n";
        }
        
        return res;
    }
};