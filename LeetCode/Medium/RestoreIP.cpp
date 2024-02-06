class Solution {
public:
    int strVal(string s){
        if(s.length() > 1 && s[0] == '0') return 256;
        
        stringstream ss(s);
        int x = 0;
        ss>>x;
        
        return x;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        
        int N = s.length();
        
        for(int i=1;i<4;i++){
            if(i >= N) continue;
            string first = s.substr(0,i);
            
            if(first.length() > 3) continue;
            if(strVal(first) >= 256) continue;
            
            for(int j=1;j<4;j++){
                if(i+j+1 >= N) continue;
                string second = s.substr(i,j);
                
                if(second.length() > 3) continue;
                if(strVal(second) >= 256) continue;
                
                for(int k=1;k<4;k++){
                    if(i+j+k >= N) continue;
                    
                    string third = s.substr(i+j,k);
                    
                    if(third.length() > 3) continue;
                    if(strVal(third) >= 256) continue;
                    
                    string fourth = s.substr(i+j+k);
                    
                    if(fourth.length() > 3) continue;
                    if(strVal(fourth) >= 256) continue;

                    // cout<<first<<"."<<second<<"."<<third<<"."<<fourth<<"\n";
                    res.push_back(first + "." + second + "." + third + "." + fourth);
                }
            }
        }
        
        return res;
    }
};