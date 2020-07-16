#include<iostream>
using namespace std;
unsigned int swapBitsInPair(unsigned int x) 
{ 
    return ((x & 0b10101010) >> 1) |  
            ((x & 0b01010101) << 1);     
} 
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    unsigned int n;
	    cin>>n;
	    unsigned ans=swapBitsInPair(n);
	    cout<<ans<<endl;
	}
	return 0;
}
