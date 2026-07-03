# include<bits/stdc++.h>
using namespace std; 


void print(deque<int> dq){
     while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}


int main(){
    deque<int>dq;

    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_front(40);
    // 10 20 40
    dq.push_back(60);
    dq.push_back(70);
    // 70 60 10 20 40

    cout<<dq.size()<<endl;
    cout<<dq.empty()<<endl;

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    

    
    
    



 return 0;
}