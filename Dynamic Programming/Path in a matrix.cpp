#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int PathInMatrix(int n,vector<vector<int>>& arr){
    vector<vector<int>> dp;
    dp=arr;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int a=dp[i-1][j];
            if(j-1>=0){
                a=max(a,dp[i-1][j-1]);
            }
            if(j+1<n){
                a=max(a,dp[i-1][j+1]);
            }
            dp[i][j]=a+arr[i][j];
        }
    }
    int max_val=dp[n-1][0];
    for(int i=1;i<n;i++){
        max_val=max(max_val,dp[n-1][i]);
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
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        cout<<PathInMatrix(n,arr)<<endl;
    }
	return 0;
}
