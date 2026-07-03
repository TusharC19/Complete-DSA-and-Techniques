# include<bits/stdc++.h>
using namespace std; 

class Node{
    public:
        int data;
        Node* next; // pointer to node not int

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        ~Node(){
            int valstore = this->data;
            // memory free
            if(this->next != NULL){
                delete next;
                next = NULL;
            }
            cout<<"memory is free for node with data "<<valstore<<endl;
        }

};

Node* insertHead(int val,Node* &head,Node* &tail){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
    tail = newnode;
    return head;
  
}

void printNode(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int getLength(Node* &head){
    int cnt =0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


void insertAtHead(int val,Node* &head,Node* &tail){
    if(head == NULL && tail == NULL){
        Node* newnode = new Node(val);
        head = newnode;
        tail = newnode;
    }
    else{
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }
    
}

void insertAtTail(int val,Node* &head,Node* &tail){
    if(head == NULL && tail == NULL){
        Node* newnode = new Node(val);
        head = newnode;
        tail = newnode;
    } 
    else{
        Node* newnode = new Node(val);
        tail->next = newnode;
        tail = newnode;
    }
    
}


void insertAtPosition(int val,Node* &head,Node* &tail,int pos){
    int len = getLength(head);

    if(pos == 1){
        insertAtHead(val,head,tail);
    }
    else if(pos == len+1){
        insertAtTail(val,head,tail);
    }
    else{
        Node* newnode = new Node(val);
        Node* temp = head;  
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

}

bool searchLL(Node* &head,int value){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

void deleteNode(Node* &head,Node* &tail,int val){
    // empty list
    if(head == NULL && tail == NULL) {
    cout << "No node to delete" << endl;
    return;
    }
    //single node in LL
    if(head == tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    
    if(head->data == val){
        // first element to delete
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
        

    else{
        // last element 
        // middle element

        Node* curr = head;
        Node* prev = head;

        while(curr->data != val ){
            curr = curr->next;
        }
        while(prev->next != curr){
            prev = prev->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
    }
   
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;
  
    insertAtHead(10,head,tail);
    insertAtHead(20,head,tail);
    insertAtHead(30,head,tail);

    deleteNode(head,tail,30);
    printNode(head);


    // insertAtTail(100,head,tail);
    // insertAtTail(200,head,tail);
    // insertAtTail(300,head,tail);

    // insertAtPosition(55,head,tail,4);
    // insertAtPosition(55,head,tail,1);
    // insertAtPosition(55,head,tail,6);
    

    // int len = getLength(head);
    // cout<<len<<endl;
    // printNode(head);

    // bool ans = searchLL(head,200);
    // cout<<ans<<endl;
    

    // Node* node = new Node(10);
    // cout<<ans->data<<endl;
    // cout<<head->data<<endl;


    // dynamic memory example
    // int* a = new int(10);
    // cout<<a<<endl;
    // cout<<*a<<endl;

    // stack memory
    // Node firstnode(100);
    // cout<<firstnode.data<<endl;

    // Dynamic memory allocation
    // Node* node = new Node(10);


    
    
 return 0;
}