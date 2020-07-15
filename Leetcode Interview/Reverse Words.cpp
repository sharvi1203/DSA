class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        int size=s.size();
        string temp="";
        int i=0,j=size-1;
        while(s[i]==' '){
            i++;
        }
        while(s[j]==' '){
            j--;
            size--;
        }
        for(;i<=size;i++){
            if(s[i]==' ' && s[i+1]==' '){
                continue;
            }
            if(s[i]!=' ' && i<size){
                temp+=s[i];
            }else if(s[i]==' ' || i==size){
                ans.push_back(temp);
                temp="";
            }
        }
        int size1=ans.size();
        for(int i=0;i<size1;i++){
            cout<<ans[i]<<"+";
        }
        for(int i=size1-1;i>0;i--){
                temp+=ans[i]+' ';
        }
        temp+=ans[0];
        return temp;
    }
};
