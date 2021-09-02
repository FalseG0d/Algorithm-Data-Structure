class Solution {
public:
    int check[256];
    int map[256];
    
    bool checkMap(){
        for(int i=0;i<256;i++){
            if(map[i] < check[i]) return false;
            }
        
        return true;
    }
    
    string minWindow(string s, string t) {
        memset(check,0,sizeof(check));
        memset(map,0,sizeof(map));
        
        for(char ch:t) check[ch]++;
        
        int beg = 0;
        int end = 0;
        
        string res = "";
        
        int N = s.length();
        
        while(end < N){
            map[s[end]]++;
            
            while(map[s[beg]] > check[s[beg]]){
                map[s[beg]]--;
                beg++;
            }
            
            end++;
            if(checkMap()){
                string temp = s.substr(beg,end - beg);
                if(res.length() == 0) res = temp;
                else res = res.length() > temp.length() ? temp : res;
                
                // res = temp;
            }
        }
        
        return res;
    }
};