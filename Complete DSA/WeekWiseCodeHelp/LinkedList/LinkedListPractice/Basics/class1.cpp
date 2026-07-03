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

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

void insertAtHead(int data,Node* &head,Node* &tail){
    
    if(head == NULL && tail == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }

    else{
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
    }
}

void insertAtTail(int data,Node* &head,Node* &tail){
    
    if(head == NULL && tail == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }

    else{
        Node* newnode = new Node(data);
        tail->next = newnode;
        tail = newnode;
    }
}


void insertAtPostion(int postion,int data,Node* &head,Node* &tail){
    
    int len = getLength(head);
    // Assume karke chal rha hu ki valid pos i.e 1 to len+1 tak hi dega
    if(postion == 1){
        insertAtHead(data,head,tail);

    }
    else if(postion == len+1){
        insertAtTail(data,head,tail);
    }
    else{
        Node* newnode = new Node(data);
        Node* temp = head;
        for(int i=0;i<postion-2;i++){
            temp = temp->next;
        }
        // Node* newnode = new Node(data);
        Node* forward = temp->next;
        newnode->next = forward;
        temp->next = newnode;

    }
}


void deleteNode(int position,Node* &head,Node* tail){

    if(head==NULL && tail == NULL){
        cout<<"Empty"<<endl;
    }

    else if(head==tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }

    else if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else{
        Node* temp = head;
        for(int i=0;i<position-2;i++){
            temp = temp->next;
        }
        Node* curr = temp->next;
        Node* forward = curr->next;
        temp->next = forward;
        curr->next = NULL;
        delete curr;

        

    }






}





int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    // print(head);
    // insertAtHead(10,head,tail);
    // print(head);
    // insertAtHead(20,head,tail);
    insertAtHead(30,head,tail);
    insertAtHead(40,head,tail);

    print(head);

    insertAtTail(12,head,tail);
    insertAtTail(34,head,tail);
    // insertAtTail(890,head,tail);
    // insertAtTail(128,head,tail);

    print(head);

    // int len = getLength(head);
    // cout<<len<<endl;

  
    // insertAtPostion(2,67,head,tail);
    // insertAtPostion(3,78,head,tail);
    
    
    // insertAtPostion(7,28,head,tail);
    insertAtPostion(1,23,head,tail);


    print(head);

    int len = getLength(head);
    cout<<len<<endl;


    deleteNode(5,head,tail);
    print(head);

    

  


























}