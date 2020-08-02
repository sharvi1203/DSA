#include <bits/stdc++.h>
#define R 6
#define C 5
using namespace std;
bool isValid(int x,int y1,int y2){
    return x>=0 && x<R && y1>=0 && y2>=0 && y1<C && y2<C;
}
int getMaxUtil(int arr[R][C],int dp[R][C][C],int x,int y1,int y2){
    if(!isValid(x,y1,y2)){
        return INT_MIN;
    }
    if(x==R-1 && y1==0 && y2==C-1){
        return (y1==y2)?arr[x][y1]:arr[x][y1]+arr[x][y2];
    }
    if(x==R-1){
        return INT_MIN;
    }
    if(dp[x][y1][y2]!=-1)   return dp[x][y1][y2];
    int ans=INT_MIN;
    int temp=(y1==y2)?arr[x][y1]:arr[x][y1]+arr[x][y2];
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1,y2-1));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1,y2+1));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1,y2));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1+1,y2-1));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1+1,y2+1));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1+1,y2));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1-1,y2-1));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1-1,y2+1));
    ans=max(ans,temp+getMaxUtil(arr,dp,x+1,y1-1,y2));
    dp[x][y1][y2]=ans;
    return dp[x][y1][y2];
}
int getMaxCollection(int arr[R][C]){
    int dp[R][C][C];
    memset(dp,-1,sizeof(dp));
    return getMaxUtil(arr,dp,0,0,C-1);
}
int main() {
	int arr[R][C] = {{9, 10, 15, 12,11}, 
                     {7, 5, 11, 6, 8}, 
                     {4, 1, 27, 13, 17}, 
                     {2, 4, 18, 2, 1}, 
                     {15, 3, 22, 6, 10},
                     {8, 2, 5, 9, 6},
                    }; 
    cout << "Maximum collection is " << getMaxCollection(arr); 
    return 0; 
}
