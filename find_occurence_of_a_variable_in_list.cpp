#include<iostream>
using namespace std;

struct  Node {
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class LinkedList{
    public:
    struct Node* head;
    void push(int item);
    void print();
    int  count_number(int);
    void Remove_duplicacy();
};

void LinkedList::push(int item){
        Node* temp = new Node(item);
        temp->next = head;
        head = temp;
}
void LinkedList::print(){
        Node* ptr = head;
        while(ptr){
                cout<<ptr->data<<"|";
                ptr = ptr->next;
        }
}
int  LinkedList::count_number(int n){
        Node* ptr = head; int count = 0;
        cout<<"inside count::"<<ptr->data<<endl;
        while(ptr){
            if(ptr->data == n)
                count++;
            ptr = ptr->next;
        }
        return count;
}
void LinkedList::Remove_duplicacy(){
        Node* ptr1 = head,*temp,*ptr2,*alt;
        while(ptr1 != NULL){
            ptr2 = ptr1->next; temp = ptr1;
            while(ptr2->next != NULL){
                if(ptr2->data == ptr1->data){
                    alt = ptr2;
                    temp->next = ptr2->next;
                    ptr2 = ptr2->next; temp = temp->next;
                    delete alt;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
}
int main(){
    LinkedList l1; int n;
    l1.head = new Node(1);
    l1.push(2);
    l1.push(4);
    l1.push(3);
     l1.push(4);
     l1.push(5);
     l1.push(4);
     l1.push(3);
      l1.print();
      cout<<"Number::\n";
      cin>>n;
      cout<<"Number of times::"<<l1.count_number(n)<<endl;
      l1.Remove_duplicacy();
     l1.print();  cout<<endl;
      return 0;
}