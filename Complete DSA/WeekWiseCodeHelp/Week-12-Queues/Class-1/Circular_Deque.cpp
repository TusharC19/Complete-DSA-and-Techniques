# include<bits/stdc++.h>
using namespace std; 

class CircularDeqQ{
    private:
        int* arr;
        int size;
        int front;
        int rear;

    public:
        CircularDeqQ(int s){
            size = s;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void pushFront(int val){
            // full
            if((front == 0 && rear == size-1) ||(front==rear+1)) cout<<"OverFlow Condition"<<endl;
            // first element
            else if(front == -1 && rear == -1){
                front++,rear++;
                arr[front] = val;
            }
            // circular nature
            else if(front == 0 && rear != size-1){
                front = size-1;
                arr[front] = val;
            }
            else{
                // normal case
                front--;
                arr[front] = val;
            }
        }

        void pushBack(int val){
            if((front == 0 && rear == size-1) || (rear==front-1)) cout<<"OverFlow Condition"<<endl;

            else if(front == -1 && rear == -1){
                rear++,front++;
                arr[rear] = val;
            }
            // circular nature
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = val;
            }
            else{
                // normal case
                rear++;
                arr[rear] = val;
            }

        }

        void popBack(){
            if(rear == -1 && rear == -1) cout<<"UnderFlow Condition"<<endl;
                // Single element case
                else if(rear == front){
                    arr[front] = 0;
                    rear = -1,front = -1;
                }
                // circular case
                else if(rear==0){
                    arr[rear] = 0;
                    rear = size-1;
                }
                // normal case
                else{
                    arr[rear] = 0;
                    rear--;
                }
        }

        void popFront(){
                if(rear == -1 && rear == -1) cout<<"UnderFlow Condition"<<endl;
                // Single element case
                else if(rear == front){
                    arr[front] = 0;
                    rear = -1,front = -1;
                }
                //circular nature
                else if(front == size-1){
                    arr[front] = 0;
                    front = 0;
                }
                // normal case
                else{
                    arr[front] = 0;
                    front++;
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
    
    CircularDeqQ q(5);

    q.pushFront(10);
    q.pushFront(20);
    q.pushFront(30);

    q.print();

    q.pushBack(44);
    q.pushBack(33);

    q.print();

    q.pushBack(100);
    q.pushFront(98);

    q.popBack();
    q.print();

    q.popFront();
    q.popFront();
    q.popFront();
    q.popFront();

    q.popBack();

    q.print();


 return 0;
}