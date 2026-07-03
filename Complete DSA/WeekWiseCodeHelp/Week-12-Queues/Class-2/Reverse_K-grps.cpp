# include<bits/stdc++.h>
using namespace std; 

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverseInKgrp(queue<int>&q,int k,int cnt){
    
    if(cnt>=k){
        stack<int>s;

        for(int i=0;i<k;i++){
            int ele = q.front();
            q.pop();
            s.push(ele);
        }

        for(int i=0;i<k;i++){
            int ele = s.top();
            s.pop();
            q.push(ele);
        }

        reverseInKgrp(q,k,cnt-k);
    }

    else{
        for(int i=0;i<cnt;i++){
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
    }
}


int main(){
    queue<int>q;
    q.push(10);
    q.push(20);    
    q.push(30);    
    q.push(40);    
    q.push(50);    
    q.push(60);    
    q.push(70);    
    q.push(80);    
    q.push(90);    
    q.push(100);
    q.push(110);    

    print(q);
    int cnt = q.size();
    int k = 3;

    reverseInKgrp(q,k,cnt);

    print(q);
 return 0;
}