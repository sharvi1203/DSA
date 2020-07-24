#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MaxSumIncSubsequence(vector<int> v,int n){
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        dp[i]=v[i];
    }
    int max_val=dp[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j]<v[i] && dp[i]<v[i]+dp[j]){
                dp[i]=v[i]+dp[j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(max_val<dp[i]){
            max_val=dp[i];
        }
    }
    return max_val;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    cout<<MaxSumIncSubsequence(v,n)<<endl;
	}
	return 0;
}
