# include<bits/stdc++.h>
using namespace std; 

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

// time complexity - O(n)
void reverseq(queue<int>&q){
    stack<int>s;
    while(!q.empty()){
        int n = q.front();
        s.push(n);
        q.pop();
    }
    while(!s.empty()){
        int n = s.top();
        q.push(n);
        s.pop();
    }
    
}

void reverseRec(queue<int>&q){
    
    if(q.empty()) return;
    int n = q.front();
    q.pop();
    reverseRec(q);
    q.push(n);
    return;
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print(q);
    reverseRec(q);
    // reverseq(q);
    print(q);

 return 0;
}