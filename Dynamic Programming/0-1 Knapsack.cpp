#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,W;
	    cin>>n>>W;
	    int v[n],wt[n];
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>wt[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=W;j++){
	            if(wt[i-1]<=j){
	                dp[i][j]=max(v[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    cout<<dp[n][W]<<endl;
	}
	return 0;
}
