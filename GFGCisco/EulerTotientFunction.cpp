/*
Euler Totient Function (ETF) Φ(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n.

Output:
Print the Euler Totient Function Φ(n) for an input n.

Constraints:
1<=T<=10^5
1<=N<=10^5

Example:
Input:
2
11
16

Output:
10
8

** For More Input/Output Examples Use 'Expected Output' option **
*/
#include<iostream>
#include<algorithm>
using namespace std;
// int gcd(int a,int b){
//     if(b==0){
//         return a;
//     }
//     return gcd(b,a%b);
// }
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int count=1;
	    for(int i=2;i<n;i++){
	       // if(gcd(n,i)==1){
	       //     count++;
	       // }
	       if(__gcd(n,i)==1){
	           count++;
	       }
	       
	    }
	    cout<<count<<endl;
	}
	return 0;
}
