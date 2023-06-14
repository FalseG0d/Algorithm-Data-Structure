#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int count,i;
    for(i=0;s[i],t[i];i++)
        if(s[i]!=t[i])        
        break;
    int n1=s.size(),n2=t.size();
    count=n1-i+n2-i;
    
    if(k==count||k>=n1+n2)       // Case 1
    return "Yes";
    
    else if(count%2==k%2 && count<=k) // Case 2
    return "Yes";
    
    else               // Case 3
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
