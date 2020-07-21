bool compare(struct val p1,struct val p2){
    return p1.first<p2.first;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,compare);
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].second<p[i].first && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
    int max_val=dp[0];
    for(int i=1;i<n;i++){
        if(max_val<dp[i]){
            max_val=dp[i];
        }
    }
    return max_val;
}
//Sort krna zaruri dry run soch thodaa
