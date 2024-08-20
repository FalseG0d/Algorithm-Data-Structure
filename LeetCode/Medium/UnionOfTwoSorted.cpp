class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> res;
        
        int itr1 = 0;
        int itr2 = 0;
        
        for(int i=1;i<n;i++) {
            if(arr1[itr1] != arr1[i]) arr1[++itr1] = arr1[i];
        }
        
        n = itr1+1;
        
        for(int i=1;i<m;i++) {
            if(arr2[itr2] != arr2[i]) arr2[++itr2] = arr2[i];
        }
        
        m = itr2+1;
        
        itr1 = itr2 = 0;
        
        while(itr1 < n && itr2 < m) {
            if(arr1[itr1] == arr2[itr2]) {
                res.push_back(arr1[itr1]);
                
                itr1++;
                itr2++;
            } else if(arr1[itr1] < arr2[itr2]) {
                res.push_back(arr1[itr1]);
                
                itr1++;
            } else {
                res.push_back(arr2[itr2]);
                
                itr2++;
            }
        }
        
        while(itr1 < n) {
            res.push_back(arr1[itr1]);
                
            itr1++;
        }
        
        while(itr2 < m) {
            res.push_back(arr2[itr2]);
                
            itr2++;
        }
        
        return res;
    }
};