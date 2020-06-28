#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int TotalValues(string str){
    int n=str.size();
    vector<int> dp(n+1,1);
    dp[0]=1;
    dp[1]=(str[0]=='0')?0:1;
    for(int i=2;i<=n;i++){
        dp[i]=0;
        if(str[i-1]>='1'){
            dp[i]+=dp[i-1];
        }
        if(str[i-2]=='1' || str[i-2]=='2'&& str[i-1]<'7'){
            dp[i]+=dp[i-2];
        }
        dp[i]=dp[i]%mod;
    }
    return dp[n];
}
int main()
{
    while(1){
        string str;
        cin>>str;
        if(str=="0"){
            break;
        }
        cout<<TotalValues(str)<<endl;
    }
    return 0;
}
