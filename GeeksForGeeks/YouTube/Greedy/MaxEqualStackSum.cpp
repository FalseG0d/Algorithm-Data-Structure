#include <iostream>
using namespace std;

int stackSum(int arr[],int top){
    int s=0;

    while(top>=0)s+=arr[top--];

    return s;
}

int maxEqualSum(int stack1[],int stack2[],int stack3[],int top1,int top2,int top3){
    int sum1=stackSum(stack1,top1);
    int sum2=stackSum(stack2,top2);
    int sum3=stackSum(stack3,top3);

    cout<<sum1<<" "<<sum2<<" "<<sum3<<"\n";

    while(top1>=0 && top2>=0 && top3>=0){
        if(sum1 == sum2 && sum2 == sum3) break;
        
        if(sum1>sum2){
            if(sum1>sum3){//Sum1 Is Greatest
                sum1-=stack1[top1];
                top1--;
            }
            else{//Sum3 Is Greatest
                sum3-=stack3[top3];
                top3--;
            }
        }else{
            if(sum2>sum3){////Sum2 Is Greatest
                sum2-=stack2[top2];
                top2--;
            }
            else{////Sum3 Is Greatest
                sum3-=stack3[top3];
                top3--;
            }
        }
    }

    if(sum1 == sum2 && sum2 == sum3)return sum1;
    else return -1;
}

int main() {
    int stack1[5]={1,1,1,2,3};
    int stack2[3]={2,3,4};
    int stack3[4]={1,4,5,2};

    int top1=4;
    int top2=2;
    int top3=3;

    cout<<maxEqualSum(stack1,stack2,stack3,top1,top2,top3);

    return 0;
}