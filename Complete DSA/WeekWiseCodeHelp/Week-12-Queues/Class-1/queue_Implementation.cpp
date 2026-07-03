# include<bits/stdc++.h>
using namespace std; 

// Normal Queue
class Queue{
    private:
        int* arr;
        int size; // since using arr so size is taken
        int front;
        int rear;

    public:
        Queue(int s){
            size = s;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int n){

            if(rear == size-1) cout<<"Overflow"<<endl;

            // first elment
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

        void pop(){

            if(rear == -1 && front == -1) cout<<"UnderFlow"<<endl;

            // first element
            else if(rear == front){
                arr[rear] = 0;
                rear = -1 ,front = -1;
            }
            else{
                // normal case - delete from front
                arr[front] = 0;
                front++;
            }
        }

        int getfront(){
            if(front == -1) cout<<"Queue is empty"<<endl;
            else{
                return arr[front];
            }
        }

        int getrear(){
            if(rear == -1) cout<<"Queue is empty"<<endl;
            else{
                return arr[rear];
            }
        }

        int getlen(){

            if(front == -1 && rear == -1) return 0;
            else{
                int len = rear - front + 1;
                return len;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1) return true;
            else return false;

        }      

        void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

  

int main(){

    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(600);

    cout<<"length of queue is : "<<q.getlen()<<endl;
    cout<<q.getrear()<<endl;
    cout<<q.getfront()<<endl;

    string s = q.isEmpty() ? "Empty" : "Not Empty";
    cout<<s<<endl;

    // q.pop();
    // q.pop();
    // q.pop();

    cout<<"length of queue is : "<<q.getlen()<<endl;
    
    string s1 = q.isEmpty() ? "Empty" : "Not Empty";
    cout<<s1<<endl;

    q.print();

    
 return 0;
}