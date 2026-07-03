# include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void insertAtBottom(stack<int>&s, int val){
    // base case
    if(s.empty()){
        // insert val
        s.push(val);
        return;
    }

    ///ek case mera baki recursion karega
    int topelement = s.top();
    // yha top element store ho gya in this variable
    s.pop();

    /// recursive call kiya
    insertAtBottom(s,val);

    // wapas ate time insert kara topelement ko at each recursive call
    s.push(topelement);

    
}


int main(){

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int val = 23;
    insertAtBottom(s,val);
    print(s);



    return 0;
}