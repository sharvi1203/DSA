#include<iostream>
using namespace std;
int MaximizeNumber(int* arr,int n,int m){
    int left=0,right=0;
    int max_len=0;
    int zero=0;
    while(right<n){
        if(zero<=m){
            if(arr[right]==0){
                zero++;
            }
            right++;
        }
        else if(zero>m){
            if(arr[left]==0){
                zero--;
            }
            left++;
        }
        if(max_len<(right-left) && zero<=m){
            max_len=right-left;
        }
    }
    return max_len;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    int* arr=new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>m;
	    cout<<MaximizeNumber(arr,n,m)<<endl;
	}
	return 0;
}
