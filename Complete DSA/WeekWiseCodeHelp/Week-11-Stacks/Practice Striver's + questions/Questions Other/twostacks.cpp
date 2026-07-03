# include<bits/stdc++.h>
using namespace std; 

class twoStacks {
    
  public:
    int *arr;
    int size;
    int top1,top2;
    

    twoStacks(int n) {
        arr = new int[n];
        size = n;
        top2=size;
        top1=-1;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(top2-top1>1){
            top1++;
            arr[top1]=x;
        }
        else cout<<"s1 full\n";
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top2-top1>1){
            top2--;
            arr[top2]=x;
        }
        else cout<<"s2 full\n";
    }
    // Function to remove an element from top of the stack1.
    int pop1() {
        // code here
        if(top1==-1) return -1;

        int element = arr[top1];
        top1--;
        return element;
        
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(top2==size) return -1;

        int element = arr[top2];
        top2++;
        return element;
    }
};


int main(){
    twoStacks s(4);
    s.push1(1);
    s.push1(2);
    s.push2(15);
    s.push2(10);

    cout<<s.pop1()<<" ";
    cout<<s.pop1()<<" ";
    cout<<s.pop2()<<" ";
    cout<<s.pop2()<<" ";
    cout<<s.pop1()<<" ";


 return 0;
}