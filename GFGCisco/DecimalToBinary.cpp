#include<iostream>
using namespace std; 
void decimalToBinary(int n){
    if(n==1){
        cout<<1;
        return;
    }
    decimalToBinary(n/2);
    cout<<(n%2);
}
int main()
 {
     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         decimalToBinary(n);
         cout<<endl;
     }
	return 0;
}
