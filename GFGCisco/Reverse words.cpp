void reverseWords(char *s) {
     string str=s;
     string temp="";
     int size=str.size();
     vector<string> v;
     for(int i=0;i<size;i++){
          if(str[i]!='.'){
              temp+=str[i];
              if(i==size-1){
                  v.push_back(temp);
              }
          }else{
              v.push_back(temp);
              temp="";
          }
     }
     temp="";
     size=v.size();
     for(int i=size-1;i>=1;i--){
         cout<<v[i]<<".";
     }
     cout<<v[0];
}
