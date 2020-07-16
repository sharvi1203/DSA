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
	    int res=n&mask;
	    if(res > 0){
	        cout<<"Yes";
	    }else{
	        cout<<"No";
	    }
	    cout<<endl;
	}
	return 0;
}
