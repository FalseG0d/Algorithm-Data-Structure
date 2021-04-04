#include<iostream>
#include<vector>

 using namespace std;
 
 int binaryToInt(vector<int>v){
    int x=1;
    int res=0;
    
    for(int i=v.size()-1;i>=0;i--){
        res+=v[i]*x;
        x*=2;
    }
    
    return res;
 }
 
 void help(vector<int> arr,int pos,vector<int>&res){
     if(pos==-1)return;

     arr[pos]=1;
     help(arr,pos-1,res);
     arr[pos]=0;

     for(int i=arr.size()-1;i>=0;i--){
         if(i==pos)continue;
        //  if(arr[i]==1)continue;

         arr[i]=1;
         res.push_back(binaryToInt(arr));
         arr[i]=0;
     }

     
     res.push_back(binaryToInt(arr));
     arr[pos]=1;     
     help(arr,pos-1,res);
 }

 vector<int> grayCode(int n) {
 	 //Write your code here
      vector<int> binArr;
      for(int i=0;i<n;i++)binArr.push_back(0);

      vector<int>res;
      help(binArr,n-1,res);
      return res;
 }
     
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> res = grayCode(n);
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }