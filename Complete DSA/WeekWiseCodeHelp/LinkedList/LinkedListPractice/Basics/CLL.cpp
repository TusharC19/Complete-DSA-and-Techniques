# include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void printNode(Node* tail){ // by value pass so tail not change its original location
    Node* temp = tail;
    // while(tail->next != temp){
    //     cout<<tail->data<<"->";
    //     tail = tail->next;
    // }cout<<endl;
    
    if(tail == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    // for single node case
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}


void insertNode(Node* &tail,int element,int value){

    // empty list
    if(tail == NULL){
        Node* newnode = new Node(value);
        tail = newnode;
        newnode->next = newnode;
    }
    
    else{
       Node* curr = tail;
       while(curr->data != element){
        curr = curr->next;
       }
       // nopw pahuch gya at element
       // curr at element
       Node* temp = new Node(value);
       temp -> next = curr->next;
       curr -> next = temp;
    }
}

void deleteNode(Node* &tail,int value){

    //empty CLL
    if(tail == NULL){
      cout<<"List is empty, please check again"<<endl;
      return;
    }
   
    // not empty list
    else{
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
        
    }
    prev->next = curr->next;

    // 1 node wala case
    if(curr == prev){
        tail = NULL;
    }

    // >2 wali linked list
    // for first element delete
    if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
    
    }
    
}




int main(){

    // Node* n = new Node(10);
    // cout<<n->data<<" "<<n->next<<endl;
    Node* tail = NULL;

    // empty list me insert
    // insertNode(tail,5,3);
    // printNode(tail);

    // insertNode(tail,3,7);
    // printNode(tail);

    // insertNode(tail,7,34);
    // printNode(tail);
    // insertNode(tail,3,5);
    // printNode(tail);

    // insertNode(tail,5,8);
    // insertNode(tail,8,11);
    // insertNode(tail,11,23);
    // insertNode(tail,23,45);

    // printNode(tail);

    // insertNode(tail,5,6);
    // insertNode(tail,11,15);

    // printNode(tail);
    

    deleteNode(tail,7);
    // printNode(tail);

    // deleteNode(tail,4);
    // printNode(tail);

    

    

  


   

    return 0;
}