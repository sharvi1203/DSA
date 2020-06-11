/*
  Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address. 
*/

class Solution {
public:
    string validIPv6="0123456789abcdefABCDEF";
    bool isValidIPv4(string temp){
        if(temp.size()>0 && temp.size()<4){
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<endl;
                if((!isalnum(temp[i]) )|| (temp[i]>='a' && temp[i]<='z')|| (temp[i]>='A' && temp[i]<='Z') || (temp[0]=='0' && temp.size()>1)){
                    return false;
                }  
            }
            return stoi(temp)<=255 && stoi(temp)>=0;
        }
        return false;
    }
    bool isValidIPv6(string& block) {
    	if (block.size() > 0 && block.size() <= 4) {
    	    for (int i = 0; i < block.size(); i++) {
    	        char c = block[i];
    	        if (validIPv6.find(c) == string::npos)
    	    	    return false;
    	    }
    	    return true;
    	}
    	return false;
    }
    string validIPAddress(string IP) {
        int len=IP.size();
        if(IP.find('.')!=string::npos){
            //Check for IPv4;
            vector<string> v;
            string temp="";
            //split
            int count=0;
            for(int i=0;i<=len;i++){
                if(IP[i]!='.' && i<len){
                    temp+=IP[i];
                }else if(IP[i]=='.' ){
                    count++;
                    v.push_back(temp);
                    temp="";
                }else if(i==len){
                     v.push_back(temp);
                }
            }
            if(count!=3){
                return "Neither";
            }
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
                if(!isValidIPv4(v[i])){
                    return "Neither";
                }
            }
            return "IPv4";
        }else{
            //check IPv6
            vector<string> v;
            string temp="";
            //split
            int count=0;
            for(int i=0;i<=len;i++){
                if(IP[i]!=':' && i<len){
                    temp+=IP[i];
                }else if(IP[i]==':'){
                    //cout<<temp<<endl;
                    count++;
                    v.push_back(temp);
                    temp="";
                }else if(i==len){
                     v.push_back(temp);
                }
            }
            if(count!=7){
                return "Neither";
            }
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<endl;
                if(!isValidIPv6(v[i])){
                    return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};
