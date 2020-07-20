#include<bits/stdc++.h>
using namespace std;
void printkMax(int arr[],int n,int k){
    deque<int> q(k);
    int i;
    for(i=0;i<k;i++){
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++){
        cout<<arr[q.front()]<<" ";
        while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()];
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    printkMax(arr,n,k);
	    cout<<endl;
    }
	return 0;
}
