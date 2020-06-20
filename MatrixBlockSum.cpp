/*
    Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.


    Example 1:

    Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
    Output: [[12,21,16],[27,45,33],[24,39,28]]
    Example 2:

    Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
    Output: [[45,45,45],[45,45,45],[45,45,45]]


    Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n, K <= 100
    1 <= mat[i][j] <= 100
*/

/*
  Explanation: https://leetcode.com/problems/matrix-block-sum/discuss/482730/Python-O(-m*n-)-sol.-by-integral-image-technique.-90%2B-with-Explanation
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i-1][j-1];
            }
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r1=max(0,i-K),c1=max(0,j-K),r2=min(n-1,i+K),c2=min(m-1,j+K);
                r1++;   c1++;   r2++;   c2++;
                ans[i][j]=dp[r2][c2]-dp[r2][c1-1]-dp[r1-1][c2]+dp[r1-1][c1-1];
            }
        }
        return ans;
    }
};
