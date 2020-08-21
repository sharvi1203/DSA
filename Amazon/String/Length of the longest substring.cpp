#include<bits/stdc++.h>
using namespace std;
int Length(string str){
    int i=0,j=0,n=str.size(),max_len=0;
    unordered_map<char,int> map;
    /*  
        g   e   e   k   s   f   o   r   g   e   e   k   s 
                i              j
    */  
    while(j<n){
        map[str[j]]++;
        if(map[str[j]]>1){
            map[str[j]]--;
            while(i<j && str[i]!=str[j]){
                map[str[i]]--;
                i++;
            }
            i++;
        }
        max_len=max(max_len,j-i+1);
        j++;
    }
    return max_len;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    cout<<Length(str)<<endl;
	}
	return 0;
}
/*
    
    
    
                                        
    i   j
    
    e->1
    g->0
    
    len=3,max_len=7
*/
