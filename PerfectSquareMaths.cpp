/*
  Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

  Example 1:

  Input: n = 12
  Output: 3 
  Explanation: 12 = 4 + 4 + 4.
  Example 2:

  Input: n = 13
  Output: 2
  Explanation: 13 = 4 + 9.
*/

class Solution {
public:
    bool isSquare(int n){
        int val=(int)(sqrt(n));
        return (val*val == n);
    }
    int numSquares(int n) {
        //Lagranges 4 - sqaure theoram states that a natural number can be represented in the form of sum of square of    
        //atmost 4 values
        // Therefore least number can be either 1 , 2 , 3 ,4;
        // the ans can only be 4 if n can be represented as 4^k(8m+7)
        if(isSquare(n)){
            return 1;
        }
        //n%4==0
        while((n&3) == 0){
          n>>=2;  //decresing by 2^2;  
        }
        
        //n%8==7
        if((n&7) == 7){
            return 4;  
        }
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (isSquare(n - i*i)) 
            {
                return 2;  
            }
        } 
        return 3;
    }
};
