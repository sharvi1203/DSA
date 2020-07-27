#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int coinChange(int arr[],int n,int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=dp[i][j-arr[i-1]]+dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,sum;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>sum;
	    cout<<coinChange(arr,n,sum)<<endl;
	}
	return 0;
}
