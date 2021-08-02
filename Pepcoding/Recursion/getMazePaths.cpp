#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr==dr && sc==dc){
        vector<string>v;
        v.push_back("");
        
        return v;
    }
    
    vector<string>res;
    if(sr<0 || sc<0) return res;
    if(sr>dr || sc>dc) return res;
    
    vector<string>ret;
    
    ret=getMazePaths(sr,sc+1,dr,dc);
    for(string s:ret) res.push_back("h"+s);
    
    ret=getMazePaths(sr+1,sc,dr,dc);
    for(string s:ret) res.push_back("v"+s);
    
    return res;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}