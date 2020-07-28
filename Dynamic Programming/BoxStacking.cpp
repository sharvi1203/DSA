class Dimension{
    public:
        int l;
        int h;
        int w;
    Dimension(){
        
    }
    Dimension(int len,int hei,int wid){
        l=len;
        h=hei;
        w=wid;
    }
};
Dimension createAllDimension(int height,int side1,int side2){
        Dimension d1;
        d1.h=height;
        if(side1>=side2){
            d1.l=side1;
            d1.w=side2;
        }else{
            d1.l=side2;
            d1.w=side1;
        }
        return d1;
}
bool mycompare(Dimension d1,Dimension d2){
    int area1=d1.l * d1.w;
    int area2=d2.l * d2.w;
    return area1>area2;
}
int maxHeightUtil(vector<Dimension>& combi){
    int n=combi.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        dp[i]=combi[i].h;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(combi[j].l>combi[i].l && combi[j].w>combi[i].w){
                if(dp[i]<dp[j]+combi[i].h){
                    dp[i]=dp[j]+combi[i].h;
                }
            }
        }
    }
    int max_val=dp[0];
    for(int i=1;i<n;i++){
        max_val=max(max_val,dp[i]);
    }
    return max_val;
}
int maxHeight(int height[],int width[],int length[],int n)
{
    vector<Dimension> v;
    for(int i=0;i<n;i++){
        Dimension d=createAllDimension(height[i],width[i],length[i]);
        v.push_back(d);
    }
    vector<Dimension> combo;
    for(int i=0;i<n;i++){
        Dimension d1=v[i];
        combo.push_back(d1);
        Dimension d2=createAllDimension(d1.l,d1.h,d1.w);
        combo.push_back(d2);
        Dimension d3=createAllDimension(d1.w,d1.l,d1.h);
        combo.push_back(d3);
    }
    sort(combo.begin(),combo.end(),mycompare);
    return maxHeightUtil(combo);
}
