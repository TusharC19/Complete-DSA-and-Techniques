# include<bits/stdc++.h>
using namespace std; 

class Queue{
  public:
    int size;
    int* arr;
    int front,rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front=-1,rear=-1;
    }

    void push(int val){
        if(rear == size-1) cout<<"Overflow\n";
        else if(front==-1 && rear==-1){
            front++,rear++;
            arr[front] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        if(front==-1 && rear==-1) cout<<"underflow\n";
        else if(front==rear){
            arr[rear]=0;
            rear--,front--;
        }
        else{
            arr[front] = 0;
            front++;
        }
    }

    int getfront(){
        return arr[front];
    }

    int getrear(){
        return arr[rear];
    }

    bool isEmpty(){
        if(front==-1 && rear==-1 || front>rear) return true;
        return false;
    }

    void print(){
        for(int i=0;i<size;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }

};


int main(){
    Queue q(5);
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);

    // q.print();

    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();

    // q.pop();
    cout<<q.isEmpty()<<endl;


    // q.print();







 return 0;
}