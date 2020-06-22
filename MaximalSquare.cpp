/*
    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    Example:

    Input: 

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0

    Output: 4
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=(rows>0)?matrix[0].size():0;
        vector<int> dp(cols+1,0);
        int maxSquare=0,prev=0;
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                int temp=dp[j];
                if(matrix[i-1][j-1]=='1'){
                    dp[j]=min(min(dp[j-1],prev),dp[j])+1;
                    maxSquare=max(maxSquare,dp[j]);
                }else{
                    dp[j]=0;
                }
                prev=temp;
            }
        }
        return maxSquare*maxSquare;
    }
};
