# include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};
/// we are taking the track of head and tail so we are passing by reference
void insertAtHead(int data, Node* &head, Node* &tail) {
  //2 cases -> LL is empty / non-empty
  //empty wala case
  if(head == NULL && tail == NULL) {
    //iska mtlb, main firstb node create krne wala hu 
    Node* newNode = new Node(data);
    head = newNode;
    tail= newNode;
  }
  else {
    //LL is not empty
    Node* newNode = new Node(data);
    newNode->next = head;
    head -> prev = newNode;
    head = newNode;
  }
}

void insertAtTail(int data,Node* &head,Node* &tail){
        // empty list
         if(head == NULL && tail == NULL){
            Node* newnode = new Node(data);
            head = newnode;
            tail = newnode;
        }
        // not empty;
        else{
            Node* newnode = new Node(data);
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }

}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

void printReverse(Node* &tail){
    Node* temp = tail;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->prev;
    }cout<<"NULL"<<endl;

}

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;

}

void insertAtPosition(int position,int data, Node* &head, Node* &tail) {

  //3 cases -> leftmost end, rightmost end, middle me insert krna chahte ho
  int len = getLength(head);
  if(position == 1) {
    //insert leftmost me krna chahte h 
    insertAtHead(data, head,tail);
  }
  else if(position == len+1) {
    //rightmost end pr insert krna chahta hu
    //tail pr insert krna chahta hu
    insertAtTail(data, head, tail);
  }
  else if(position<1 || position>len+1){
    cout<<"enter a valid position to enter"<<endl;
  }
  else {
    //middle me kisi poistion pr insert krna chahta hu 
    Node* temp = head;
    //fer main temp ko position-2 steps aage badhaya 
    for(int i=0; i<position-2; i++) {
      temp = temp ->next;
    }
    //create node
    Node* newNode = new Node(data);
    //forward pointer set
    Node* forward = temp->next;
    //pointers ko set krra hu 
    newNode->prev = temp;
    temp->next = newNode;
    forward->prev = newNode;
    newNode->next = forward;
  }
  

}

int searchLL(int element,Node* &head){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == element){
                return (temp->data);
            }
            temp = temp->next;
        }
        return -1;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

   
   
    insertAtHead(30,head,tail);
    insertAtHead(40,head,tail);
    insertAtHead(20,head,tail);
    insertAtHead(10,head,tail);

    // print(head);
      printReverse(tail);
}