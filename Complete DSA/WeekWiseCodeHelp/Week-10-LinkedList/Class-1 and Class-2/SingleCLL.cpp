# include<bits/stdc++.h>
using namespace std; 


// Circular LL me sirf tail chahiye
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


void printNode(Node* &tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp != tail);
    
    
    // while(temp->next != tail){
    //     cout<<temp->data<<"->";
    //     temp = temp->next;
    // }
    // cout<<"NULL"<<endl;
}

int getLength(Node* &tail){
    int cnt =0;
    Node* temp = tail;
    while(temp->next != temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertNode(int element,int val,Node* &tail){
    
    // Empty list
    if(tail == NULL){
        Node* newnode = new Node(val);
        tail = newnode;
        newnode->next = newnode;
    }

    // single LL
    else{
        Node* newnode = new Node(val);
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* forward = curr->next;
        newnode->next = forward;
        curr->next = newnode;
    }
    
}


bool searchLL(Node* &tail,int value){
    Node* temp = tail;
    while(temp != NULL){
        if(temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

void deleteNode(Node* &tail,int val){
    // empty list
    if(tail == NULL) {
    cout << "No node to delete" << endl;
    return;
    }
    //single node in LL
    if(tail->next == tail){
        Node* temp = tail;
        tail = NULL;
        temp->next = NULL;
        delete temp;
    }
    // tail ko delete kar rhe ho
    // if(tail->data == val){
    //     Node* temp = tail;
    //     tail = tail->next;
    //     tail->next = temp->next;
    //     temp->next = NULL;
    //     delete temp;
    // }   

    else{
        // first element
        // last element 
        // middle element    
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != val){
            prev = curr;
            curr = curr->next;
        }
        // curr -> prev->curr(tail) ->prev
        if(curr == tail){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;          
    }
   
}


int main(){

    Node* tail = NULL;

    insertNode(1,10,tail);
    insertNode(10,20,tail);
    // insertNode(20,30,tail);
    // insertNode(30,40,tail);

    // insertNode(20,100,tail);
    printNode(tail);
    cout<<endl;

    // deleteNode(tail,100);
    // printNode(tail);
    // cout<<endl;
    // deleteNode(tail,40);
    // printNode(tail);
    // cout<<endl;
    // deleteNode(tail,10);
    // printNode(tail);
    // cout<<endl;

    deleteNode(tail,10);
    printNode(tail);
    cout<<endl;

    // Node* node = new Node(10);
    // cout<<node->next->data<<endl;
       
 return 0;
}