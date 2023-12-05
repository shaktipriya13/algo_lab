#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int knapsack(int w,int wt[],int val[],int n){
    if(n==0||w==0){
        return 0;
    }
    if(wt[n-1]>w){
        return knapsack(w,wt,val,n-1);
    }
    else{
        return max(val[n-1]+knapsack(w-wt[n-1],val,wt,n-1),
        knapsack(w,wt,val,n-1));
    }
}
int main()
    {
    int profit[]={60,100,120};
    int weight[]={10,20,30};
    int w=50;
    int n=sizeof(profit)/sizeof(profit[0]);
    printf("%d",knapsack(w,weight,profit,n));
    return 0;
}
