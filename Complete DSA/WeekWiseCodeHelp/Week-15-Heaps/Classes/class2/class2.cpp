# include<bits/stdc++.h>
using namespace std; 

int main(){

    // min heap -> priority given to smallest element
    // priority_queue<int,vector<int>,greater<int>> pq;
    // pq.push(30);    
    // pq.push(60);    
    // pq.push(90);    
    // pq.push(20);    
    // pq.push(10);

    // while(!pq.empty()){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }

    //  by deault max heap - max heap
    priority_queue<int>pq;
    
    pq.push(30);    
    pq.push(60);    
    pq.push(90);    
    pq.push(20);    
    pq.push(10);

    pq.pop();
    cout<<pq.top()<<endl;
    // while(!pq.empty()){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }


    // // by deault max heap
    // priority_queue<string>q;
    // q.push("arun");
    // q.push("karan");
    // q.push("sammer");
    // q.push("sohan");

    // while(!q.empty()){
    //     cout<<q.top()<<endl;
    //     q.pop();
    // }



 return 0;
}