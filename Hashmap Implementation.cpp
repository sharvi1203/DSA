#include <bits/stdc++.h>
using namespace std;
//We have key value pair in hashing, key can be generic also but for now lets take key as a string type 
template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;
    
    MapNode(string key,V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};
template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numBuckets;
    
    public:
    ourmap(){
        count=0;
        numBuckets=5;
        buckets=new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i< numBuckets;i++){
            delete buckets[i];
        }
        delete[] buckets;
    }
    int size(){
        return count;
    }  
    V getValue(string key){
         int bucketIndex=getBucketIndex(key);
         MapNode<V>* head=buckets[bucketIndex];
         while(head!=NULL){
             if(head->key == key){
                 return head->value;
             }
             head=head->next;
         }
         return 0;
    }
    private: // issliye kyunki bahar valo ko kya lena dena about hashfunction
    int getBucketIndex(string key){
        int hashcode=0;
        int currentCoeff=1;
        for(int i=key.length()-1;i>=0;i--){
            hashcode+=key[i]*currentCoeff; //abcd -> hashcode=> a*p^3+b*p^2+c*p^1+d*p^0     p ussually taken as  prime number
            hashcode=hashcode%numBuckets; // Taaki voh integer ki range se bahr na jaye    (abc)%m  ->((a%m)*(b%m)*(c%m))%m
            currentCoeff*=37;
            currentCoeff=currentCoeff%numBuckets;
        }
        
        return hashcode%numBuckets;
    }
    void rehash(){
        MapNode<V>** temp=buckets;
        buckets=new MapNode<V>*[2* numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i]=NULL;
        }
        int oldBucketCount=numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0;i<oldBucketCount;i++){
            MapNode<V>* head=temp[i]; 
            while(head!=NULL){
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i< oldBucketCount;i++){
            MapNode<V>* head=temp[i]; 
            delete head;
        }
        delete[] temp; 
    }
    public:
    void insert(string key,V value){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        MapNode<V>* node=new MapNode<V>(key,value);
        node->next=head;
        buckets[bucketIndex]=node;
        count++;
        double loadFactor=(1.0*count)/numBuckets;   //why 1.0 se multiply bcoz count aur numBuckets int hai toh division 0 aajega 
        //Rehash
        if(loadFactor >0.7){
            rehash();
        }
    }
    V remove(string key){
         int bucketIndex=getBucketIndex(key);
         MapNode<V>* head=buckets[bucketIndex];
         MapNode<V>* prev=NULL;
         while(head!=NULL){
             if(head->key==key ){
                 if(prev==NULL){
                    buckets[bucketIndex]=head->next; 
                 }else{
                    prev->next=head->next;
                 }
                 V value=head->value;
                 head->next=NULL; // kyu kyunki destructor jab call hoga usne head se aage vala sab uda dena hai
                 count--;
                 delete head;
                 return value;
             }
             prev=head;
             head=head->next;
         }
         return 0;
    }
};
int main() {
	// your code goes here
	ourmap<int> m;
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        m.insert(key,value);
    }
    cout<<m.size()<<endl;
    m.remove("abc2");
    m.remove("abc3");
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<< ":" <<m.getValue(key)<<endl;
    }
    cout<<m.size()<<endl;
	return 0;
}
