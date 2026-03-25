
#include <unordered_map>
#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    int data;
    Node *prev;
    Node *next;
    Node(int key, int val){
        this->key=key;
        data=val;
        next=prev=nullptr;
    }
};
class LRU{
    public:
Node *head;
Node *tail;
int capacity;
unordered_map<int,Node *>mp;
public:
LRU(int cap){
head=tail=nullptr;
capacity=cap;
}
// add to front
void addToFront(Node * node){
      if(!head) {
        head=node;
        tail=node;
      }

      else{ 
    node->prev=NULL;
    node->next=head;
     head->prev=node;
    head=node;
      }
   
}
// Remove Node
void removeNode(Node * node){
    if(node==head){
        head=head->next;
        if(head)
        head->prev=nullptr;
        
    }
    else if(node==tail){
        tail=tail->prev;
        if(tail)
        tail->next=nullptr;


    }
    else {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->prev=NULL;
        node->next=NULL;

    }
}
int getKey(int key){
    if(mp.find(key)==mp.end())
    return -1;
    Node* node=mp[key];
    removeNode(node);
    addToFront(node);
    return node->data;
}
void put(int key , int value){
    if(mp.find(key)!=mp.end()){
        Node* node=mp[key];
        removeNode(node);
        node->data=value;
    addToFront(node);
    }
    else {
        int count=0;
        Node *temp=head;
        // o(n)
        // while(temp){
        //     count++;
        //     temp=temp->next;
        // }
        // o(1)
        count=mp.size();
        if(count==capacity){
            // delete tail
           Node *temp=tail;
           removeNode(temp);
           mp.erase(temp->key);
           delete temp;
            }
       
        Node *newNode=new Node(key,value);
        mp[key]=newNode;
        addToFront(newNode);

}
}
};

int main() {
    LRU cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.getKey(1) << endl; // 10

    cache.put(3, 30); // removes key 2

    cout << cache.getKey(2) << endl; // -1
    cout << cache.getKey(3) << endl; // 30

    cache.put(4, 40); // removes key 1

    cout << cache.getKey(1) << endl; // -1
    cout << cache.getKey(3) << endl; // 30
    cout << cache.getKey(4) << endl; // 40

    return 0;
}
