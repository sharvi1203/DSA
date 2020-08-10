#include<iostream>
using namespace std;
void SubsetWithGivenSum(int* arr,int n,int sum){
    int curr_sum=arr[0];
    int start=0,last=1;
    for(int last=1;last<n;last++){
        curr_sum+=arr[last];
        while(curr_sum>sum){
            curr_sum-=arr[start++];
        }
        if(curr_sum==sum){
            cout<<start+1<<" "<<last+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n,sum;
        cin>>n>>sum;
        int* arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        SubsetWithGivenSum(arr,n,sum);
    }
	return 0;
}
