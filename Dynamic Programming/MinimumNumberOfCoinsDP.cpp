#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int t;
    cin>>t;
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    vector<vector<int>> v(1000001);
    v[0].push_back(0);
    for(int i=0;i<10;i++)
        v[coins[i]].push_back(coins[i]);
    
    for(int i = 3 ;i<100001;i++){
        
        if(i==5 || i==10 || i==20 || i==50 || i==100 || i==200 || i==500 || i==2000)
            continue;
            
        int min = INT_MAX;
        int index=0;
        int coin=0;
        for(int j=0;j<10;j++){
            
           if(coins[j]>i)
                break;
                
           if(v[i-coins[j]].size()<min){
               
               min = v[i-coins[j]].size();
               index = i-coins[j];
               coin = coins[j];
           }
        }
        
        v[i] = v[index];
        v[i].push_back(coin);
    }
    
    
    while(t--){
        
        int n;
        cin>>n;
        for(int i=0;i<v[n].size();i++)
            cout<<v[n][i]<<" ";
            
       cout<<endl;
        
        
        
    }
    
    return 0;
}
