#define ll long long
// Function to find inversion count in the array

ll _mergeSort(ll arr[], ll temp[],
ll left, ll right);
ll merge(ll arr[], ll temp[], ll left,
ll mid, ll right);




long long int inversionCount(long long arr[], long long N)
{
// Your Code Here

ll temp[N];
return _mergeSort(arr,temp,0,N-1 );
}
ll _mergeSort(ll arr[],ll temp[],ll left,ll right){
ll mid,inver_count=0;
if(right>left){
mid=(right+left)/2;
inver_count+=_mergeSort(arr,temp,left,mid);
inver_count+=_mergeSort(arr,temp,mid+1,right);

inver_count+=merge(arr,temp,left,mid+1,right);
}
return inver_count;

}


// arr[]: Input Array
// N : Size of the Array arr[]

ll merge(ll arr[],ll temp[],ll left,ll mid,ll right){
ll i,j,k;
ll inver_count=0;
i=left;
j=mid;
k=left;

while((i<=mid-1) &&(j<= right)){
if(arr[i]<=arr[j]){
temp[k++]=arr[i++];
}
else{
temp[k++]=arr[j++];
inver_count+=(mid-i);
}

}
while(i<=mid-1){
temp[k++]=arr[i++];

}

while(j<=right){
temp[k++]=arr[j++];

}
for(ll i=left;i<=right;i++){
arr[i]=temp[i];
}
return inver_count;
}