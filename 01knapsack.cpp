// memoized method


#include<iostream>
using namespace std;
int dp[10000][10000];

int knapsack(int w[],int v[],int n,int W){
    if(n==0 || W==0) return 0;
    if(dp[n][W]!=-1)   return dp[n][W];
    if(w[n-1]<=W){
        return  (dp[n][W] = max(v[n-1]+knapsack(w,v,n-1,W-w[n-1]),knapsack(w,v,n-1,W)));
    }
    else if(w[n-1]>W)
        return (dp[n][W]= knapsack(w,v,n-1,W));
}

int main(){
    int n,W;
    cout<<"Enter no of items\n";
    cin>>n;
    cout<<"Enter maximum weight\n";
    cin>>W;
    int w[n],v[n];
    memset(dp,-1,sizeof(dp));
    cout<<"Enter weights of the elements\n";
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    cout<<"Enter values of the elements\n";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<knapsack(w,v,n,W);
    return 0;
}