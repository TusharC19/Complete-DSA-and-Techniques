// # include<bits/stdc++.h>
# include<iostream>
using namespace std; 

class Stack{
  public:
    int size;
    int* arr;
    int top;

    Stack();

    Stack(int capacity){
        arr = new int[capacity];
        top = -1;
        size = capacity;
    }  

    void push(int val){
        if(top == size-1) cout<<"Overflow condition"<<endl;
        else{
            top++;
            arr[top] = val;
        }

    }

    void pop(){
        if(top==-1) cout<<"UnderFlow condition"<<endl;
        else{
            arr[top] = 0;
            top--;
        }
        
    }

    int getTop(){
        if(top==-1) cout<<"Stack is empty"<<endl;
        else{
        return arr[top];
        }
    }

    int getSize(){
        // if(top == -1) return 0;
        // else{
        //     int cnt = 0;
        //     for(int i=0;i<=top;i++){
        //         cnt++;
        //     }
        //     return cnt;
        // }
        return top+1;
    }

    bool isEmpty(){
        if(top==-1) return true;
        else return false;
    }

    void print(){
        // if(top==-1) cout<<"Stack is empty"<<endl;
        for(int i=0;i<size;i++){
           cout<<arr[i]<<endl;
        }
       
    }
};



int main(){

    Stack s(5);

    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);



    // s.print();

    s.pop();
    s.pop();
    
    s.print();

    cout<<s.getTop()<<endl;

    string st = s.isEmpty() ? "Empty" : "NotEmpty";
    cout<<st<<endl;

    cout<<s.getSize()<<endl;



    

    
    return 0;
}