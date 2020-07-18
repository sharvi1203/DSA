#include<iostream>
using namespace std;
int swapNibbles(int n){
    return ((n&0x0F)<<4 |(n&0xF0)>>4);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<swapNibbles(n)<<endl;
	}
	return 0;
}
