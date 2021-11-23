#include <iostream>
#include <string>

using namespace std;

template <typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode*next;

    MapNode(string key , V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
};

template <typename V>

class ourmap{
    MapNode<V>**buckets;
    int count;
    int numBuckets;

public:
    ourmap(){
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        count = 0;
        for(int i=0;i<numBuckets;i++){
            buckets[i] = NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<numBuckets;i++){
            buckets[i];
        }
        delete[] buckets;
    }

    int getSize(){
        return count;
    }

private:
    int getBucketIndex(string key){
        int hashcode = 0;
        int currentCoeff = 1;

        for(int i = key.length()-1 ; i>=0 ; i--){
            hashcode += key[i]*currentCoeff;
            hashcode = hashcode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff%numBuckets;
        }

        return hashcode%numBuckets;
    }

public:
    void insert(string key , V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>*head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>*node = new MapNode<V>(key,value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        double loadFactor = (1.0*count)/numBuckets;

        if(loadFactor > 0.7){
            rehash();
        }
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>*head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>*head = buckets[bucketIndex];
        MapNode<V>*prev = NULL;
        while(head!=NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }
                else{
                    prev->next = head->next;
                }

                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;


        }
        return 0;
    }

    void rehash(){
        MapNode<V>*temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        int oldBucketCount = numBuckets;
        numBuckets = numBuckets*2;
        count = 0;

        for(int i=0;i<oldBucketCount;i++){
            MapNode<V>*head = temp[i];
            while(head!=NULL){
                string key = head->key;
                V value = head->value;

                insert(key,value);

                head = head->next;
            }
        }

    }
};


