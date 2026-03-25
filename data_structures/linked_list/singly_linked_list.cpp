#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node (int val){
        data = val;
        next = nullptr;
    }
};
class Linkedlist {
    Node *head;
    public:
    Linkedlist (){
          head=nullptr;
    }
    // Insertion at Head
    void insertAtHead(int val){
    Node * newNode=new Node(val);
       newNode->next=head;
       head=newNode;
       
    }
    // DisplayLimited
   void displayLimited(int limit = 20) {
        Node* temp = head;
        int count = 0;

        while(temp && count < limit){
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }

        if(count == limit)
            cout << "... (cycle suspected)";
        else
            cout << "NULL";

        cout << endl;
    }
    //  Insertion at Tail
    void insertionAtTail(int val){
        Node * newNode =new Node(val);
        Node* temp=head;
        if(!temp) {
            head=newNode;
            return;
        }
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    // Reverse
    void reverse(){
             Node *prev=nullptr;
             Node *curr=head;
             if(!head) return;
         
             while(curr){ 
                Node * temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                 }
                head= prev;
    }
    //  Search
    bool search(int key){
         Node * temp=head;
         if(!temp) return false;
         while(temp){
          if(temp->data==key) return true;
          temp=temp->next;
         }
         return false;
    }
    //   Find Middle
    int findMidddle(){
        Node* slow=head;
        Node * fast=head;
        while(fast&&fast->next){
           slow=slow->next;
           fast=fast->next->next;
        }
        return slow?slow->data:-1;
    }
    // Detect Cycle
    bool detectCycle(){
           Node* slow=head;
        Node * fast=head;
        while(fast&&fast->next){
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow) return true;
        }
     return false;
      
    }
    // Detect LengthofLoop
    int lengthofLoop(){
           Node* slow=head;
        Node * fast=head;
        while(fast&&fast->next){
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow) break;
        }
        if(fast!=slow) return 0;
        slow=head;
        int count=0;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
            count++;
        }
        return count;

    }
    // CYCLE CREATION
    void createCycle() {
    if (!head || !head->next) return;

    Node* temp = head;

    // go to last node
    while (temp->next) {
        temp = temp->next;
    }

    // create cycle (last node → second node)
    temp->next = head->next;
}
};


int main() {
    Linkedlist list;
    int choice, value;

    while (true) {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Display\n";
        cout << "4. Reverse\n";
        cout << "5. Search\n";
        cout << "6. Find Middle\n";
        cout << "7. Detect Cycle\n";
        cout << "9. Create Cycle\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtHead(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertionAtTail(value);
            break;

        case 3:
            list.displayLimited();
            break;

        case 4:
            list.reverse();
            cout << "List reversed\n";
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;

        case 6:
            cout << "Middle: " << list.findMidddle() << endl;
            break;

        case 7:
            if (list.detectCycle())
                cout << "Cycle Detected\n";
            else
                cout << "No Cycle\n";
            break;

            case 8:
                list.createCycle();
              cout << "Cycle created\n";
                 break;

            case 9:
                 return 0;


           default:
            cout << "Invalid choice\n";
        }
    }
}