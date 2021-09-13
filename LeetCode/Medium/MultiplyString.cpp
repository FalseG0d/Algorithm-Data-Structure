class Solution {
public:
    vector<int> strToVec(string num){
        int N = num.length();
        vector<int>res;
        
        for(int i=N-1;i>=0;i--) res.push_back(num[i] - '0');
        
        return res;
    }
    string multiply(string num1, string num2) {
        vector<int>n1 = strToVec(num1);
        vector<int>n2 = strToVec(num2);
        
        // for(int ele : n1) cout<<ele<<" ";
        // cout<<"\n";
        // for(int ele : n2) cout<<ele<<" ";
        // cout<<"\n";
        
        int size = 0;
        
        int N1 = n1.size();
        int N2 = n2.size();
        
        vector<int>res(N1 + N2 + 1, 0);
        
        int multi = 0;
        int carry = 0;
        
        for(int i=0;i<N1;i++){
            for(int j=0;j<N2;j++){
                multi = n1[i] * n2[j];
                
                res[i + j] += multi + carry;
                
                carry = res[i + j] / 10;
                res[i + j] %= 10;
            }
            
            res[i + N2] += carry;
            carry = 0;
        }
        
        reverse(res.begin(),res.end());
        
        bool beg = false;
        string ret = "";
        
        for(int ele:res){
            if(ele > 0) beg = true;
            if(!beg) continue;
            
            ret += std::to_string(ele);
        }
        
        return ret.size() > 0 ? ret : "0";
    }
};