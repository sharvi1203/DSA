/*
Given a number N and a value K. From the right, set the Kth bit in the binary representation of N. The position of LSB(or last bit) is 0, second last bit is 1 and so on. Also, 0 <= K < X, where X is the number of bits in the binary representation of N.

Input:
First line of input contains a single integer T, which denotes the number of test cases. T test cases follows. First line of each testcase contains two space separated integers N and K.

Output:
For each test case, print the new number after setting the Kth bit of N.

Constraints:
1 <= T <= 100
1 <= N <= 1000

Example:
Input:
2
10 2
15 3

Output:
14
15

Explanation:
Testcase 1: Binary representation of the given number 10 is: 1 0 1 0, number of bits in the binary reprsentation is 4. Thus 2nd bit from right is 0. The number after changing this bit to 1 is: 14(1 1 1 0).

** For More Input/Output Examples Use 'Expected Output' option **
*/
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int mask=1<<k;
	    int ans=n | mask;
	    //cout<<mask<<" "<<ans;
	    cout<<ans<<endl;
	}
	return 0;
}
