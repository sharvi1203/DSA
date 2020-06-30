class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        for(long long i=5;n/i>=1;i*=5){
            count+=n/i;
        }
        return count;
    }
};

/*
n/5^k >=1
n>=5^k
log5(n)=k
so time complexity will be log5(n)
*/
