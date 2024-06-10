// top down 
#include<iostream>
using namespace std;
bool dp[1000][1000];
bool subsetSum(int a[],int n,int Sum){

    for(int i=0;i<=Sum;i++)
        dp[0][i]=false;
    for(int i=0;i<=n;i++)
        dp[i][0]=true; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=Sum;j++){
            if(a[i-1]<=Sum)
                dp[i][j]= dp[i-1][j-a[i-1]] || dp[i-1][j];
            else    
                dp[i][j]= dp[i-1][j];
        }
    }
    return dp[n][Sum];
}
int main(){
    int n,Sum;
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    int totSum=0;
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
        totSum+=a[i];
    }
    if(totSum%2==0)
        cout<<subsetSum(a,n,totSum/2);
    else
        cout<<"Equal sum partition not possible\n";
    return 0;
}