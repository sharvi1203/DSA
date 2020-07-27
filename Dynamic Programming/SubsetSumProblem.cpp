#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool subsetSumProblem(int arr[],int n,int sum){
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j]|dp[i-1][j-arr[i]];
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
	    int n;
	    cin>>n;
	    int arr[n],sum=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    if(sum%2!=0){
	        cout<<"NO"<<endl;
	    }else{
	        bool val=subsetSumProblem(arr,n,sum);
	        if(val){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }
	    }
	    
	}
	return 0;
}
