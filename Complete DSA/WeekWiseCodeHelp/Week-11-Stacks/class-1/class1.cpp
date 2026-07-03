# include <iostream>
# include <vector>

using namespace std;

class stack{
    public:
    int* arr;
    int size;
    int top;

    stack(int sizeArr){
        arr = new int[sizeArr]; // Heap memory allocation
        size = sizeArr;
        top = -1; // initially
    }

    void push(int val){
        /// overflow handling
        if(top == size-1){
            /// stack is already full
            cout<<"Stack is Full"<<endl;
        }
        else{
            //// Stack is not full
            top++;
            arr[top] = val;
        }

    }

    void pop(){
        /// stack underflow case
        if(top == -1){
            cout<<"Stack is Empty"<<endl;
        }
        else{
            // not empty
            arr[top] = 0;
            top--;

        }
    }

    int gettop(){
       if(top == -1){
        cout<<"stack is empty"<<endl;
        return -1;
       }    
       else {
        return arr[top];
       }
    }

    int getsize(){
      
        /*
        int stacksize = 0;
        // single element case
        // top = 0;
        if(top == -1) return 0;
        else if(top == size-1) return size-1;
        else{
            int i = top;
            while(i>-1){
                stacksize+= 1;
                i--;
            }
        }
        */
      
       // or just use
       return top+1;

    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }

    void print(){
        cout<<"printing stack"<<endl;
        if(top == -1 ) cout<<"NULL"<<endl;
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};






int main(){

    stack s(5);
    // s.print();

    s.push(10);
    s.push(20);
    s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);

    s.print();




    // yha error nhi diya
    // s.push(40); 
    // s.push(40); // yha top heap me alag memory location par ja rha hai
    // s.push(40);
    // yha error nhi diya
    
    // s.pop();
    // s.print();

    // cout<<"top element is: "<<s.gettop()<<endl;
    // int size = s.getsize();
    // cout<<"size of stack is: "<<endl;
    
    // bool e = s.isEmpty();
    // string ans = e ? "Empty" : "Not empty";
    // cout<<"string is "<<ans<<endl;
    
    
    



    

    return 0;
}