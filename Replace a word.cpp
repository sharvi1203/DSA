#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
	    string str,oldW,newW;
	    getline(cin,str);
	    getline(cin,oldW);
	    getline(cin,newW);
	    int i=0;
	    string temp="";
	    while(str.find(oldW)!=string::npos){
	        int i=str.find(oldW);
	        temp=str.substr(0,i);
	        str=temp+newW+str.substr(i+oldW.size());
	    }
	    cout<<str<<endl;
	}
	return 0;
}
/*

*/
