/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only
*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()==0 || text2.size()==0){
            return 0;
        }
        if(text1[0]==text2[0]){
            return longestCommonSubsequence(text1.substr(1),text2.substr(1))+1;
        }
        int x=longestCommonSubsequence(text1,text2.substr(1));
        int y=longestCommonSubsequence(text1.substr(1),text2);
        return max(x,y);
    }
};

#############DP##########################

class Solution {
public:
    int lcs(string text1,string text2,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return lcs(text1,text2,n,m);
    }
};
