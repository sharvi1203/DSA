class Solution {
public:
    class Job{
        public:
        int start;
        int end;
        int weight;
        Job(){
            
        }
        Job(int startTime,int endTime,int profit){
            start=startTime;
            end=endTime;
            weight=profit;
        }
    };
    static bool comparison(Job j1,Job j2){
        return j1.end<j2.end;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        Job jobs[n];
        for(int i=0;i<n;i++){
            jobs[i]=Job(startTime[i],endTime[i],profit[i]);
        }
        sort(jobs,jobs+n,comparison);
        vector<int> dp(n);
        dp[0]=jobs[0].weight;
        for(int i=1;i<n;i++){
            dp[i]=max(jobs[i].weight,dp[i-1]);
            for(int j=0;j<i;j++){
                if(jobs[j].end<=jobs[i].start){
                    dp[i]=max(dp[i],jobs[i].weight+dp[j]);
                }
            }
        }
        int max=dp[0];
        for(int i=1;i<n;i++){
            if(max<dp[i]){
                max=dp[i];
            }
        }
        return max;
    }
};
