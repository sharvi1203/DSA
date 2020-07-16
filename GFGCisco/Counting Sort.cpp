char* countSort(char arr[])
{
    int count[26];
    for(int i=0;i<26;i++){
        count[i]=0;
    }
    for(int i=0;arr[i]!='\0';i++){
        int index=arr[i]-'a';
        count[index]++;
    }
    for(int i=1;i<26;i++){
        count[i]+=count[i-1];
    }
    int size=count[25];
    char* newchar=new char[size];
    int i;
    for(i=0;arr[i]!='\0';i++){
        newchar[count[arr[i]-'a']--]=arr[i];
    }
    newchar[i]='\0';
    return newchar+1;
}
//https://practice.geeksforgeeks.org/problems/counting-sort/1
