#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int LongestCommonSubstring(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int max_val=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                max_val=max(max_val,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return max_val;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string str1="",str2="";
	    for(int i=0;i<n;i++){
	       char a;
	       cin>>a;
	       //cout<<a;
	       str1+=a;
	    }
	    for(int i=0;i<m;i++){
	       char a;
	       cin>>a;
	       str2+=a;
	    }
	    //cout<<str1<<endl;
	    cout<<LongestCommonSubstring(str1,str2)<<endl;
	}
	return 0;
}
