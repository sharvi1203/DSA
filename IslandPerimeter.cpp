/*
  You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:


*/
class Solution {
public:
    
    bool isOmitted(int i,int j,int n,int m,vector<vector<int>>& grid){
        return i<n && j<m && i>=0 && j>=0 &&  grid[i][j]==1;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int perimeter=0;
        unordered_map<
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int count=4;
                    if(isOmitted(i+1,j,n,m,grid)){
                        count--;
                    }
                    if(isOmitted(i-1,j,n,m,grid)){
                        count--;
                    }
                    if(isOmitted(i,j+1,n,m,grid)){
                        count--;
                    }
                    if(isOmitted(i,j-1,n,m,grid)){
                        count--;
                    }
                    perimeter+=count;
                }
            }
           
        }
        return perimeter;
    }
};
