class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int n1=v1.size();
        int n2=v2.size();
        
        double res;
        
        for(int ele:v2){
            v1.push_back(ele);
        }
        
        sort(v1.begin(),v1.end());
        
        // for(int ele:v1)cout<<ele<<" ";
        
        int n=v1.size();
        
        if(n%2==1)res=v1[n/2];
        else res=(double)(v1[n/2-1]+v1[n/2])/2;
        
        // cout<<"\n"<<n<<" "<<res;
        
        return res;
    }
};