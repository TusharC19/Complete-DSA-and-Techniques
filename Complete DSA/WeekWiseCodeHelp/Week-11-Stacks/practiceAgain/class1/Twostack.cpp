// # include<bits/stdc++.h>
# include<iostream>
using namespace std; 

class Stack{
    public:
    int size;
    int* arr;
    int top1,top2;

    Stack(int capacity){
        size = capacity;
        arr = new int[size];
        top1 = -1;
        top2 = size;
        
    }

    void push1(int val){
        if(top2-top1==1) cout<<"Stack is full"<<endl;
        else{
            top1++;
            arr[top1] = val;
        }
    }

    void push2(int val){
        if(top2-top1==1) cout<<"Stack is full"<<endl;
        else{
            top2--;
            arr[top2] = val;
        }
    }

    void pop1(){
        if(top1==-1) cout<<"Stack1 is empty"<<endl;
        else{
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2(){
        if(top2==size) cout<<"Stack2 is empty"<<endl;
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

    Stack s(6);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    

    s.push2(50);
    s.push2(60);
    s.push2(70);
    s.push2(80);

    // s.pop1();
    // s.pop2();
    // s.pop2();


    s.print();


     return 0;
}