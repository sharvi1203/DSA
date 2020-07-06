class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0 && carry;i--){
            int sum=digits[i]+carry;
            carry=sum/10;
            digits[i]=sum%10;
        }
        if(carry!=0){
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }
};
