class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::replace(version1.begin(), version1.end(), '.', ' ');
        std::replace(version2.begin(), version2.end(), '.', ' ');
        
        stringstream ss1(version1);
        stringstream ss2(version2);
        int temp1 = 0;
        int temp2 = 0;
        
        vector<int>v1;
        vector<int>v2;
        
        while(ss1 >> temp1) v1.push_back(temp1);
        while(ss2 >> temp2) v2.push_back(temp2);
        
        int i1 = 0;
        int i2 = 0;
        
        int len1 = v1.size();
        int len2 = v2.size();
        
        while(i1 < len1 && i2 < len2){
            if(v1[i1] < v2[i2]) return -1;
            else if(v1[i1] > v2[i2]) return 1;
            // else continue;
            
            i1++;
            i2++;
        }
        
        while(i1 < len1){
            if(v1[i1] > 0) return 1;
            
            i1++;
        }
        while(i2 < len2){
            if(v2[i2] > 0) return -1;
            
            i2++;
        }
        
        return 0;
    }
};