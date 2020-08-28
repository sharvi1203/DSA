#include<bits/stdc++.h>
using namespace std;
void nextPallindrome(vector<int>& v){
    int n=v.size();
    if(n==2 || n==1 || n==3){
        cout<<-1<<endl;
        return;
    }
    if(n%2!=0){
        int index=(n/2)-1;
        for(int i=index-1;i>=0;i--){
            if(v[i]<v[i+1]){
                index=i;
                break;
            }
        }
        if(index==(n/2)-1){
            cout<<-1<<endl;
            return;
        }
        int index1=index+1,num=v[index+1];
        for(int i=index+1;i<n/2;i++){
            //254  num=5,index=1
            if(v[i]>v[index] && num>v[i]){
                index1=i;
                num=v[i];
            }
        }
        swap(v[index],v[index1]);
        sort(v.begin()+index+1,v.begin()+(n/2));
        for(int i=0;i<n/2;i++){
            v[n-i-1]=v[i];
        }
    }else{
        int index=(n/2);
        for(int i=index-1;i>=0;i--){
            if(v[i]<v[i+1]){
                index=i;
                break;
            }
        }
        if(index==(n/2)){
            cout<<-1<<endl;
            return;
        }
        int index1=index+1,num=v[index+1];
        for(int i=index+1;i<=n/2;i++){
            //254  num=5,index=1
            if(v[i]>v[index] && num>v[i]){
                index1=i;
                num=v[i];
            }
        }
        swap(v[index],v[index1]);
        sort(v.begin()+index+1,v.begin()+(n/2));
        for(int i=0;i<=n/2;i++){
            v[n-i-1]=v[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
    cout<<endl;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    vector<int> v;
	    for(int i=0;i<str.size();i++){
	        v.push_back(str[i]-'0');
	    }
	    nextPallindrome(v);
	}
	return 0;
}
/*
    33452425433
*/
