#include <iostream>
using namespace std;
int main() {
    long long n,m;
    cin>>n>>m;

    // Min Pair-> All team has similar number of pairs
    // Max Pair-> All team has 1 player but the one has all the rest

    long long min = 0;
    long long max = 0;

    long long endTeam = 0;
    long long begTeam = 0;

    // For Max
    endTeam = n-m+1;
    begTeam = 1;

    max = ((endTeam * (endTeam-1)) / 2) + ((begTeam * (begTeam-1)) / 2) * (m-1);

    // For Min
    endTeam = (n/m + 1);
    begTeam = (n/m);

    min = ((endTeam * (endTeam-1)) / 2) * (n%m) + ((begTeam * (begTeam-1)) / 2) * (m-n%m);

    cout<<min<<" "<<max;

    return 0;
}
