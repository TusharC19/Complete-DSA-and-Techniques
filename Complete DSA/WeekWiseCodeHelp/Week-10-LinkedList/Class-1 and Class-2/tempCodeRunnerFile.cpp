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
