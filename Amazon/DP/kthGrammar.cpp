class Solution {
public:
    
    int kthGrammar(int N, int K) {
        if(N==1){
            return 0;
        }
        if(N==2){
           if(K==1){
               return 0;
           }
           else{
               return 1;
           } 
        }
        long long len=pow(2,N-1);
        if(K<=len/2){
            return kthGrammar(N-1,K);
        }else{
            return !kthGrammar(N-1,K-len/2);
        }
    }
};
