#include<iostream>
using namespace std;
int pivotEle(int* arr,int n){
    int start=0,end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(mid<n && arr[mid]>arr[mid+1] && arr[mid-1]<arr[mid]){
            return mid;
        }else if(arr[mid]>arr[start]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}
/*  0       e
    1 2 3 4 5

*/
int binarySearchIncre(int* arr,int start,int end,int ele){
    
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid]>ele){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}
int binarySearchDec(int *arr,int start,int end,int ele){
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid]<ele){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}
/*
    1   2   6   8   7   4   3         ele=5
*/
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,ele;
	    cin>>n;
	    int *arr=new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>ele;
	    int piv=pivotEle(arr,n);
	    if(piv==-1){
	        cout<<binarySearchIncre(arr,0,n-1,ele)<<endl;
	    }else{
    	    int ans1=binarySearchIncre(arr,0,piv,ele);
    	    if(ans1!=-1){
    	        cout<<ans1<<endl;
    	    }else{
    	        int ans2=binarySearchDec(arr,piv,n-1,ele);
    	        cout<<ans2<<endl;
    	    }
	    }
	}
	return 0;
}
/*
    1   4   5   8   6
*/
