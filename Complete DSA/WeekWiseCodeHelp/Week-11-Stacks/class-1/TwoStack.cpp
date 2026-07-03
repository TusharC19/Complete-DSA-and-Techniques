# include<iostream>
using namespace std;

class stack{
    public:
    int* arr;
    int size;
    int top1;
    int top2;


    stack(int s){
        size = s;
        arr = new int[size];
        top1 = -1; // invalid index
        top2 = size; // invalid index
         
    }

    void push1(int v){
        /// overflow condition
        if(top2-top1 == 1) cout<<"stack is full"<<endl;
        else{ 
            top1++;
            arr[top1] = v;
        }
    }

    void push2(int v){
        /// overflow condition
        if(top2-top1 == 1) cout<<"stack is full"<<endl;
        else{ 
            top2--;
            arr[top2] = v;
        }
    }

    void pop1(){
        if(top1 == -1) cout<<"stack 1 is empty"<<endl;
        else {
            arr[top1] = 0;
            top1--; 
        }
    }

    void pop2(){
        if(top2 == size) cout<<"stack 2 is empty"<<endl;
        else{
            arr[top2] = 0;
            top2++;
        }

    }

    void print(){
        cout<<"top1 : "<<arr[top1]<<endl;
        cout<<"top2 : "<<arr[top2]<<endl;

        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
};



int main(){

    stack s(6);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    

    s.push2(50);
    s.push2(60);
    s.push2(70);

    s.push1(100);
    
    s.print();



    
    return 0;
}