# include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void insertAtBottom(stack<int>&s,int val){

    if(s.empty()){
        s.push(val);
        return;
    }

    int topElem = s.top();
    s.pop();

    insertAtBottom(s,val);

    // backtrack
    s.push(topElem);
}


void reverseStack(stack<int>&s){
    // basecase
    if(s.empty()){
        return;
    }

    int topEle = s.top();
    s.pop();

    reverseStack(s);

    // wapas ate samay
    insertAtBottom(s,topEle);
}

int main(){

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    cout<<"Before Reverse"<<endl;
    print(s); 

    reverseStack(s);
    cout<<"After reverse"<<endl;
    print(s);



    

    return 0;
}