#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    unsigned int n;
	    cin>>n;
	    unsigned int mask = 1<<31, res = 0;
        for(int i = 0; i < 32; ++i) {
            if(n & 1) res |= mask;
            mask >>= 1;
            n >>= 1;
        }
	    cout<<res<<endl;
	}
	return 0;
} 
