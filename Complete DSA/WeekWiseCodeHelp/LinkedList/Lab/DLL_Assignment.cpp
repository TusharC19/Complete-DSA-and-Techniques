# include<iostream>
using namespace std;

// Q1: Creation of DLL using Class
class Node{
    public:
        string data;
        Node* prev;
        Node* next;

        Node(string data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void insertAtHead(string data, Node* &head, Node* &tail) {
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

// Q3: Insert at last of linked list
void insertAtTail(string data,Node* &head,Node* &tail){
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

// Q2: Programm to print all the nodes data from DLL
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

// For finding the lenght
int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;

}

void insertAtPosition(int position,string data, Node* &head, Node* &tail) {

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

int searchLL(string value,Node* head){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == value){
            return 1;
        }
        temp = temp->next;
    }
    return -1;

}



Node* deleteDLL(int position,Node* head,Node*tail){

    int len = getLength(head);
    // null DLL
    if(head == NULL && tail == NULL){
        return head;
    }

    else if(head == tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        return head;
    }
    
    else if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return head;
    }
    else if(position==len){
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return head;
    }

    else{
        Node* temp = head;
        for(int i=0;i<position-2;i++){
            temp = temp->next;
        }
        Node* curr = temp->next;
        Node* forward = curr->next;
        temp->next = forward;
        forward->prev = temp;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
        return head;
    }

}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

   
   
    insertAtTail("Hello",head,tail);
    insertAtTail("40",head,tail);
    insertAtTail("xyz",head,tail);
    insertAtTail("10",head,tail);
    insertAtTail("world",head,tail);


    print(head);

}