/*
  Given a string s, partition s such that every string of the partition is a palindrome.

  Return all possible palindrome partitioning of s.

  For example, given s = "aab",
  Return

    [
      ["a","a","b"]
      ["aa","b"],
    ]
   Ordering the results in the answer : Entry i will come before Entry j if :
  len(Entryi[0]) < len(Entryj[0]) OR
  (len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
  *
  *
  *
  (len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
  In the given example,
  ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*/
bool isPalindrome(string str){
    int n=str.size();
    if(n==1){
        return true;
    }
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-i-1]){
            return false;
        }
    }
    return true;
}
void partitionUtil(string A,vector<string> &temp,vector<vector<string>> &res,int index){
    if(index==A.size()){
        res.push_back(temp);
        return;
    }
    string str="";
    for(int i=index;i<A.size();i++){
        str+=A[i];
        if(isPalindrome(str)){
           temp.push_back(str);
           partitionUtil(A,temp,res,i+1);
           temp.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > res;
    vector<string> temp;
    partitionUtil(A,temp,res,0);
    return res;
}
