/*
    Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

    For example, given the following triangle

    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
    The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

    Note:

    Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mindp=triangle[triangle.size()-1];
        int layers=triangle.size();
        for(int i=layers-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                mindp[j]=triangle[i][j]+min(mindp[j],mindp[j+1]);
            }
        }
        return mindp[0];
    }
};
