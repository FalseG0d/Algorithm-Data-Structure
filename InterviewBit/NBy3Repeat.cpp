int Solution::repeatedNumber(const vector<int> &V) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int N = V.size();

    int ele1=INT_MAX;
    int ele2=INT_MAX;

    int count1=0;
    int count2=0;

    for(int i=0;i<N;i++){
        if(ele1 == V[i]) count1++;
        else if(ele2 == V[i]) count2++;
        else if(count1 == 0){
            count1++;
            ele1=V[i];
        }
        else if(count2 == 0){
            count2++;
            ele2=V[i];
        }else{
            count1--;
            count2--;
        }
    }

    count1=count2=0;

    for(int i=0;i<N;i++){
        if(ele1 == V[i]) count1++;
        else if(ele2 == V[i]) count2++;
    }

    if(count1 > N/3) return ele1;
    if(count2 > N/3) return ele2;

    return -1;
}