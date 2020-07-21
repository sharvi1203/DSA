#include<iostream>
#include<limits.h>
using namespace std;
int minOper(int n,int sum,int len){
    if(n==0){
        return 1;
    }
    if(sum==n){
        return len;
    }
    if(sum>n){
        return INT_MAX;
    }
    int val1=minOper(n,sum+1,len+1);
    int val2=minOper(n,sum*2,len+1);
    return min(val1,val2);
}
int minOperDP(int n){
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=dp[i/2]+1;
        }else{
            dp[i]=dp[i-1]+1;
        }
    }
    return dp[n];
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	cout<<minOperDP(n)<<endl;
    }	
	return 0;
}
