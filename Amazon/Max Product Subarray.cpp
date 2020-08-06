int Solution::maxProduct(const vector<int> &A) {
    int maxFwd=INT_MIN,maxBkwd=INT_MIN;
    int max_till_now=1;
    int n=A.size();
    bool isZero=false;
    int res=0;
    for(int i=0;i<n;i++){
        max_till_now=max_till_now*A[i];
        if(max_till_now==0){
            isZero=true;
            max_till_now=1;
            continue;
        }
        if(maxFwd<max_till_now){
            maxFwd=max_till_now;
        }
    }
    max_till_now=1;
    for(int i=n-1;i>=0;i--){
        max_till_now=max_till_now*A[i];
        if(max_till_now==0){
            isZero=true;
            max_till_now=1;
            continue;
        }
        if(maxBkwd<max_till_now){
            maxBkwd=max_till_now;
        }
    }
    res=max(maxBkwd,maxFwd);
    if(isZero){
        return max(res,0);
    }
    return res;
    
}
//https://www.geeksforgeeks.org/maximum-product-subarray-set-2-using-two-traversals/
