# include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void printMiddle(stack<int>&s,int mid){
    // base case
    // if(s.size() == mid+1){
    //     cout<<s.top()<<endl;
    //     return;
    // }

    if(mid == 0){
        cout<<s.top()<<endl;
        return;
    }

    int topelement = s.top();
    s.pop();
    mid--;

    printMiddle(s,mid);
    // backtracking
    s.push(topelement);
}

int main(){

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);


    int mid = s.size()/2;
    printMiddle(s,mid);


    return 0;
}