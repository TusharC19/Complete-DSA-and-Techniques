# include<bits/stdc++.h>
using namespace std; 

void print(queue<int>&q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}


void rque(queue<int>&q){
    if(q.empty()) return;

    int ele = q.front();
    q.pop();
    rque(q);
    q.push(ele);
}

void reverseKgrpHelper(queue<int>&q,int &k,int size){
    if(size<k){
        while(size--){
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        return;
    }

    stack<int>s;
    int m=k;
    while(m--){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    reverseKgrpHelper(q,k,size-k);
    
}

void reverseKgrp(queue<int>&q,int k){
    reverseKgrpHelper(q,k,q.size());
}








int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    reverseKgrp(q,2);

    print(q);


 return 0;
}