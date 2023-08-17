class Solution {
public:
    string simplifyPath(string path) {
        int N = path.length();
        
        for(int i=0;i<N;i++) if(path[i] == '/') path[i] = ' ';
        
        stringstream ss(path);
        string str="";
        vector<string>tree;
        
        while(ss>>str){
            if(str == ".." && tree.size() > 0) tree.pop_back();
            else if(str == "." || str == "..") continue;
            else tree.push_back(str);
        }
        
        string res = "/";
        auto itr = tree.begin();
        N = tree.size();
        
        for(int i=0;i<N;i++){
            res += tree[i];
            if(i < N - 1) res += "/";
        }
        
        return res;
    }
};