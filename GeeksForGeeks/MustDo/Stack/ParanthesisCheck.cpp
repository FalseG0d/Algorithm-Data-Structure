// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int N = x.length();
        stack<char>s;
        
        for(int i=0;i<N;i++){
            if(x[i] == '(' || x[i] == '[' || x[i] == '{') s.push(x[i]);
            else{
                if(s.empty()) return false;
                
                char top = s.top();
                
                if(top == '{' && x[i] == '}') s.pop();
                else if(top == '(' && x[i] == ')') s.pop();
                else if(top == '[' && x[i] == ']') s.pop();
                
                else return false;
            }
        }
        
        return s.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends