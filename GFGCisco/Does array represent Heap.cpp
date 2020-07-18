#include<iostream>
using namespace std;
bool check(int arr[],int n){
    for(int i=0;i<n/2;i++){
        if(2*i+1<n && arr[2*i+1]>arr[i]){
            return false;
        }else if(2*i+2<n && arr[2*i+2]>arr[i]){
            return false;
        }
	}
	return true;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<check(arr,n)<<endl;
	}
	return 0;
}
