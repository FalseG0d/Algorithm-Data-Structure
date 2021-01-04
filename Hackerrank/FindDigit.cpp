#include <bits/stdc++.h>

using namespace std;

bool isDivisor(int n,int k){
    if(k==0){
        return false;
    }
    
    if(n%k==0){
        return true;
    }else{
        return false;
    }
}

// Complete the findDigits function below.
int findDigits(int n) {
    int sum=0;
    int s=n;
    while(s>0){
        int k=s%10;
        if(isDivisor(n,k)){
            sum++;
        }
        s/=10;
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
