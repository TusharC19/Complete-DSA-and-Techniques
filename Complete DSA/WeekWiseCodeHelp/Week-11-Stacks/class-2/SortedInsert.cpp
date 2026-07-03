# include<bits/stdc++.h>
using namespace std;


void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void sortedInsert(stack<int>&s,int val){

    // base case
    if(val>s.top()){
        s.push(val);
        return;
    }
    // 1 case mera 
    int topE = s.top();
    s.pop();

    sortedInsert(s,val);

    // backtrack
    s.push(topE);
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<"Before insert"<<endl;
    print(s);
    sortedInsert(s,23);
    cout<<"After Insert"<<endl;
    print(s);
    
    return 0;
}