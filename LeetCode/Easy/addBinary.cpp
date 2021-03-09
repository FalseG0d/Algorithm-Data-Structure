class Solution {
public:
    string intToString(int x){
        switch(x){
            case 0:return "0";break;
            case 1:return "1";break;
            case 2:return "2";break;
            case 3:return "3";break;
            case 4:return "4";break;
            case 5:return "5";break;
            case 6:return "6";break;
            case 7:return "7";break;
            case 8:return "8";break;
            case 9:return "9";break;
        }
        
        return 0;
    }
    int charToInt(char ch){
        switch(ch){
            case '0':return 0;break;
            case '1':return 1;break;
            case '2':return 2;break;
            case '3':return 3;break;
            case '4':return 4;break;
            case '5':return 5;break;
            case '6':return 6;break;
            case '7':return 7;break;
            case '8':return 8;break;
            case '9':return 9;break;
        }
        
        return 0;
    }
    string addBinary(string a, string b) {
        if(b=="")return a;
        if(a=="")return b;
        
        string res="";
        
        int itr1=a.length()-1;
        int itr2=b.length()-1;
        int carry=0;
        
        while(itr1>=0||itr2>=0){
            int x=0,y=0;
            if(itr1>=0)x=charToInt(a[itr1]);
            if(itr2>=0)y=charToInt(b[itr2]);
            
            int s=x+y+carry;
            carry=s/2;
            s%=2;
            
            res=intToString(s)+res;
            
            itr1--;
            itr2--;
        }
        
        if(carry>0){
            res=intToString(carry)+res;
        }
        
        return res;
    }
};