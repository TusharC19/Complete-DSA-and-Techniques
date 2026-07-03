# include<iostream>
using namespace std; 

// class Circular_Queue_Implementation
// {
// private:
//     /* data */
// public:
//     Circular_Queue_Implementation(/* args */);
//     ~Circular_Queue_Implementation();
// };
// Circular_Queue_Implementation::Circular_Queue_Implementation(/* args */)
// {
// }
// Circular_Queue_Implementation::~Circular_Queue_Implementation()
// {
// }

// using normal queue
// NOTE: Here No Overflow or Underflow Condition Occur

class CicularQ{
    private:
        int* arr;
        int size;
        int front,rear;

    public:
        CicularQ(int s){
            size = s;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int val){
            // overflow condition
            if((front == 0 && rear == size-1) || (rear == front-1)) cout<<"Overflow Conditon"<<endl;
            // first element
            else if(front == -1 && rear == -1){
                rear++,front++;
                arr[rear] = val;
            }
            // circular nature case i.e rear = size-1
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = val;
            }
            // normal case
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // no element case
            if((front == -1 && rear == -1)) cout<<"UnderFlow Condition"<<endl;
            // single element case
            else if(front == rear){
                arr[front] = 0;
                front = -1 ,rear = -1;
            }
            // circular nature i.e front == size-1
            else if(front == size-1 ){
                arr[front] = 0;
                front = 0;
            }
            // normal case
            else{
                arr[front] = 0;
                front++;
            }
        }
        
        int getSize(){
            if(front == -1 && rear == -1) return 0;

            else if(rear>=front) return (rear-front+1);

            else{// rear<front
                return (size-front + rear + 1);
            }
            
        }

        int getFront(){
            return arr[front];
        }

        int getBack(){
            return arr[rear];
        }

        bool isEmpty(){
            if(front == -1 && rear == -1) return 0;
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

    CicularQ c(5);
    c.push(10);
    c.push(20);
    c.push(30);
    c.push(40);

    c.print();
    c.push(50);
    c.print();

    c.push(11);

    c.pop();
    c.pop();
    c.pop();

    c.print();

    c.push(11);
    c.push(33);
    c.push(44);

    c.print();
    
    cout<<c.getBack()<<endl;
    cout<<c.getFront()<<endl;

    c.push(55);

    c.pop();
    c.pop();
    c.pop();
    c.pop();
    c.print();
    cout<<c.getBack()<<endl;
    cout<<c.getFront()<<endl;

    c.pop();

    c.print();
    cout<<c.getBack()<<endl;
    cout<<c.getFront()<<endl;

    c.push(10);
    c.push(20);
    c.push(30);

    c.print();
    cout<<c.getBack()<<endl;
    cout<<c.getFront()<<endl;
    
    cout<<c.getSize()<<endl;
    c.pop();
    c.pop();
    c.pop();

    c.print();
    cout<<c.getSize()<<endl;






 return 0;
}