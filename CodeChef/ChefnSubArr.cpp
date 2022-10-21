#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--){
	    int N;
	    cin>>N;
	    
	    std::vector<int> v(N);
	    for(int i=0;i<N;i++) cin>>v[i];
	    
	    int**arr1 = new int*[N];
	    int**arr2 = new int*[N];
	    
	    for(int i=0;i<N;i++){
	        arr1[i] = new int[N];
	        arr2[i] = new int[N];
	    }
	    
	    int res = 0;
	   
	   for(int i=0;i<N;i++){
	       arr1[i][i] = v[i];
	       arr2[i][i] = v[i];
	   }
	   
	   for(int i=0;i<N;i++){
	       for(int j=i+1;j<N;j++){
	           arr1[i][j] = arr1[i][j-1] + v[j];
	           arr2[i][j] = arr2[i][j-1] * v[j];
	       }
	   }git add 
	   
	   for(int i=0;i<N;i++){
	       for(int j=i;j<N;j++){
	           if(arr1[i][j] == arr2[i][j]) res++;
	       }
	   }
	   
	   
	   cout<<res<<"\n";
	}
	
	return 0;
}
