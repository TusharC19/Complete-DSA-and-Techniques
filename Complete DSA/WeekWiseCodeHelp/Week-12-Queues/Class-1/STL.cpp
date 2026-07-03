# include<bits/stdc++.h>
using namespace std; 



int main(){

    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;
    
    // cout<<q.size()<<endl;

    // cout<<q.empty()<<endl;

    // cout<<q.back()<<endl;

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }







 return 0;
}