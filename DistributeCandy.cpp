/*
  There are N children standing in a line. Each child is assigned a rating value.

  You are giving candies to these children subjected to the following requirements:

  1. Each child must have at least one candy.
  2. Children with a higher rating get more candies than their neighbors.
  What is the minimum candies you must give?
*/
int Solution::candy(vector<int> &A) {
    int n=A.size();
    vector<int> left(n,1);
    vector<int> right(n,1);
    for(int i=1;i<n;i++){
        if(A[i-1]<A[i]){
            left[i]=left[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(A[i]>A[i+1]){
            right[i]=right[i+1]+1;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=max(left[i],right[i]);
    }
    return sum;
}
