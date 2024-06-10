// recursive

// #include<iostream>
// using namespace std;
// bool subsetSum(int a[],int n,int Sum){
//     if(Sum==0)
//         return true;
//     if(n==0)
//         return false;
//     if(a[n-1]<=Sum)
//         return (subsetSum(a,n-1,Sum-a[n-1]) || subsetSum(a,n-1,Sum));
//     else if(a[n-1]>Sum)
//         return subsetSum(a,n-1,Sum);
// }
// int main(){
//     int n,Sum;
//     cout<<"Enter MAXSUM\n";
//     cin>>Sum;
//     cout<<"Enter size of array";
//     cin>>n;
//     int a[n];
//     cout<<"Enter elements\n";
//     for(int i=0;i<n;i++)
//         cin>>a[i];
//     cout<<subsetSum(a,n,Sum);
//     return 0;
// }

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
            if(a[i-1]<=j)
                dp[i][j]= dp[i-1][j-a[i-1]] || dp[i-1][j];
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
    

    cout<<subsetSum(a,n,Sum);
    return 0;
}