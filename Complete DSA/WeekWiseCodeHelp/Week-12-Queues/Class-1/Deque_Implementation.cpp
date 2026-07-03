# include<bits/stdc++.h>
using namespace std; 

class Deque{
  private:
    int* arr;
    int size;
    int front;
    int rear;

  public:
    Deque(int s){
        size = s;
        arr = new int[size];
        front = -1,rear = -1;
    }

    void pushFront(int n){
        if(front == 0) cout<<"Overflow Condition"<<endl;

        else if(front == -1 && rear == -1){
            front++,rear++;
            arr[front] = n;
        }

        else{
            // normal insertion
            front--;
            arr[front] = n;
        }
    }

    void pushBack(int n){
       
            
            if(rear == size-1) cout<<"Overflow"<<endl;
            // first element
            else if(front == -1 && rear == -1){
                front++,rear++;
                arr[rear] = n;
            }
            else{
                // normal insertion - from rear;
                rear++;
                arr[rear] = n;
            }
    }

    void popFront(){
        if(rear == -1 && front == -1) cout<<"UnderFlow"<<endl;
            // first element
        else if(rear == front){
                arr[front] = -1;
                rear = -1 ,front = -1;
            }
        else{
                // normal case - delete from front
                arr[front] = -1;
                front++;
            }
    }
    
    void popBack(){
        if(rear == -1 && front == -1) cout<<"Underflow Condition"<<endl;

        else if(rear == front){
            arr[rear] = -1;
            rear = -1;front = -1;
        }

        else{
            // normal 
            arr[rear] = -1;
            rear--;
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    Deque q(5);
    q.pushFront(10);
    q.pushBack(20);
    q.print();
    q.pushBack(30);
    q.pushBack(60);
    q.pushBack(90);

    q.print();
    q.popFront();
    q.popFront();
    q.print();

    q.pushFront(20);
    q.pushFront(10);

    q.print();
    q.popBack();
    q.popBack();

    q.print();
    // q.pushFront(33);
    q.popBack();
    q.popBack();
    q.popBack();

    q.print();

    q.popBack();
   

    
 return 0;
}