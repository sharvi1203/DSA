class Solution {
public:
    class Pair{
        public:
        char c;
        int freq;
        Pair(char ch,int f){
            c=ch;
            freq=f;
        }
    };
    class Comp{
        public:
        bool operator()(Pair a,Pair b){
            return a.freq<b.freq;
        }
    };
    
    string reorganizeString(string S) {
        int n=S.size();
        vector<int> alpha(26,0);
        vector<Pair> pairs;
        string ans="";
        for(int i=0;i<n;i++){
            alpha[S[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(alpha[i]!=0){
                pairs.push_back(Pair(i+'a',alpha[i]));
            }
        }
        priority_queue<Pair,vector<Pair>,Comp> pq;
        for(int i=0;i<pairs.size();i++){
            pq.push(pairs[i]);
        }
        while(pq.size()>1){
            Pair p1=pq.top();
            pq.pop();
            Pair p2=pq.top();
            pq.pop();
            //cout<<p1.c<<" "<<p2.c<<endl;
            ans+=p1.c;
            ans+=p2.c;
            p1.freq--;
            p2.freq--;
            if(p1.freq>0){
                pq.push(p1);
            }
            if(p2.freq>0){
                pq.push(p2);
            }
        }
        if(pq.size()==1){
            Pair p=pq.top();
            if(p.freq>1){
                return "";
            }else if(p.freq==1 && ans.size()>0 && ans.back()!=p.c){
                ans+=p.c;
            }else{
                return "";
            }
        }
        return ans;
    }
};
/*
    
                (a,1)
                       (c,1)
        
        
        
        ans  abacabac
    
*/
