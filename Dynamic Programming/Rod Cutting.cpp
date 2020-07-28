#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,x,y,z;
	    cin>>n>>x>>y>>z;
	    vector<int> dp(n+1,-1);
	    dp[0]=0;
	    for(int i=1;i<=n;i++){
	        if(i>=x && dp[i-x]>=0){
	            dp[i]=max(dp[i-x]+1,dp[i]);
	        }
	        if(i>=y && dp[i-y]>=0){
	            dp[i]=max(dp[i-y]+1,dp[i]);
	        }
	        if(i>=z && dp[i-z]>=0){
	            dp[i]=max(dp[i-z]+1,dp[i]);
	        }
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
