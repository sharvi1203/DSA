 #include<vector>	
	int longestBitonicSubarray(int *input, int n) {
		vector<int> dp1(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(input[j]<input[i]){
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }
        vector<int> dp2(n,1);
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(input[j]<input[i]){
                    dp2[i]=max(dp2[i],dp2[j]+1);
                }
            }
        }
        int ans=dp1[0]+dp2[0]-1;
        for(int i=1;i<n;i++){
            ans=max(dp1[i]+dp2[i]-1,ans);
        }
        return ans;
 	}

