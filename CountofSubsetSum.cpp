// top down 
#include<iostream>
using namespace std;
int dp[1000][1000];
int countSubsetSum(int a[],int n,int Sum){

    for(int i=0;i<=Sum;i++)
        dp[0][i]=0; 
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=Sum;j++){
            if(a[i-1]<=Sum)
                dp[i][j]= dp[i-1][j-a[i-1]] + dp[i-1][j];
            else    
                dp[i][j]= dp[i-1][j];
        }
    }
    return dp[n][Sum];
}
int main(){
    int n,Sum;
    cout<<"Enter MAXSUM\n";
    cin>>Sum;
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    

    cout<<countSubsetSum(a,n,Sum);
    
    return 0;
}
