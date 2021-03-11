class Solution {
public:
    string digToChar(int digit,int den){
        if(den==1000){
            switch(digit){
                case 1: return "M";
                    break;
                case 2: return "MM";
                    break;
                case 3: return "MMM";
                    break;
                    
                default: return "";
            }
        }else if(den==100){
            switch(digit){
                case 1: return "C";
                    break;
                case 2: return "CC";
                    break;
                case 3: return "CCC";
                    break;
                case 4: return "CD";
                    break;
                case 5: return "D";
                    break;
                case 6: return "DC";
                    break;
                case 7: return "DCC";
                    break;
                case 8: return "DCCC";
                    break;
                case 9: return "CM";
                    break;
                    
                default: return "";
            }
        }else if(den==10){
            switch(digit){
                case 1: return "X";
                    break;
                case 2: return "XX";
                    break;
                case 3: return "XXX";
                    break;
                case 4: return "XL";
                    break;
                case 5: return "L";
                    break;
                case 6: return "LX";
                    break;
                case 7: return "LXX";
                    break;
                case 8: return "LXXX";
                    break;
                case 9: return "XC";
                    break;
                    
                default: return "";
            }
        }else if(den==1){
            switch(digit){
                case 1: return "I";
                    break;
                case 2: return "II";
                    break;
                case 3: return "III";
                    break;
                case 4: return "IV";
                    break;
                case 5: return "V";
                    break;
                case 6: return "VI";
                    break;
                case 7: return "VII";
                    break;
                case 8: return "VIII";
                    break;
                case 9: return "IX";
                    break;
                    
                default: return "";
            }
        }return "";
    }
    string intToRoman(int num) {
        string res="";
        int den=1;
        
        while(num>0){
            int dig=num%10;
            num/=10;
            
            res=digToChar(dig,den)+res;
            den*=10;
        }
        
        return res;
    }
};