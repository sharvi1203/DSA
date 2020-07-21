#include<bits/stdc++.h>
using namespace std;
int arr[]={1,2,5,10,20,50,100,200,500,2000};
vector<int> minNumOfCoins(int n){
    vector<int> ans;
    for(int i=9;i>=0;i--){
        while(n>=arr[i]){
            n-=arr[i];
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> ans=minNumOfCoins(n);
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
