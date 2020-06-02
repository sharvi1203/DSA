void merge(int input[],int si,int mid,int ei){
    int arr[ei-si+1];
    int l=si,r=mid+1,i=0;
    while(l<=mid && r<=ei ){
        if(input[l]<input[r]){
            arr[i]=input[l];
            l++; 
        }else{
            arr[i]=input[r];
            r++; 
        }
        i++;
    }
    while(l<=mid){
        arr[i]=input[l];
        l++;
        i++;
    }
    while(r<=ei){
        arr[i]=input[r];
        r++;
        i++;
    }
    i=0;
    for(int j=si;j<=ei;i++,j++){
        input[j]=arr[i];
    }


}
void mergeSorting(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=(si+ei)/2;
    mergeSorting(input,si,mid);
    mergeSorting(input,mid+1,ei);
    merge(input,si,mid,ei);
}
void mergeSort(int input[], int size){
	// Write your code her
    mergeSorting(input,0,size-1);    
}
