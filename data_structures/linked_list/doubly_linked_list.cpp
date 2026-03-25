#include<iostream>
using namespace std;


class Node {
    public:
    int data;
    Node * next;
    Node * prev;
    Node (int val){
       data=val;
       next=prev=nullptr;
       
    }
};
class DoublyLinkedList{
    private:
      Node * head;
      public:
      DoublyLinkedList(){
          head=nullptr;
      }
    //   Insert at Head
    void insertAtHead(int val) {
    Node* newNode = new Node(val);

    if (!head) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
// Insert at Tail
void insertAtTail(int val) {
    Node* newNode = new Node(val);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
// Display forward 
void displayForward() {
    Node* temp = head;

    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
// Display Backward
void displayBackward() {
    Node* temp = head;

    // go to last node
    while (temp && temp->next) {
        temp = temp->next;
    }

    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL" << endl;
}
// delete node
void deleteNode(Node *node){
   if(node==head){
    head=node->next;
    if(head) head->prev=nullptr;
    delete node;
    return;
   }
   Node *prevNode=node->prev;
   Node * nextNode=node->next;
   if(prevNode) prevNode->next=nextNode;
   if(nextNode) nextNode->prev=prevNode;
}
// delete by value
void deleteByValue(int val) {
    Node* temp = head;

    while (temp) {
        if (temp->data == val) {
            deleteNode(temp);
            return;
        }
        temp = temp->next;
    }
}
};
int main() {
    DoublyLinkedList dll;
    int choice, value;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "5. Delete by Value\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            dll.insertAtHead(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dll.insertAtTail(value);
            break;

        case 3:
            cout << "Forward: ";
            dll.displayForward();
            break;

        case 4:
            cout << "Backward: ";
            dll.displayBackward();
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            dll.deleteByValue(value);
            cout << "Deleted (if found)\n";
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}