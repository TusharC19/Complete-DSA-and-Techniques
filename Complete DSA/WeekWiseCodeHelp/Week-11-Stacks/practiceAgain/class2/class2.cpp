# include<bits/stdc++.h>
using namespace std; 

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void inserAtbottom(stack<int> &s,int val){

    if(s.empty()){
        s.push(val);
        return;
    }

    int topEle = s.top();
    s.pop();

    inserAtbottom(s,val);

    s.push(topEle);
    return;
}

void printmiddle(stack<int> &s,int mid){

    if(mid==0){
        cout<<s.top()<<endl;
        return;
    }

    int topEle = s.top();
    s.pop();
    mid--;

    printmiddle(s,mid);

    s.push(topEle);
    return;
}

void Sreverse(stack<int> &s){

    if(s.empty()) return;

    int topEle = s.top();
    s.pop();

    Sreverse(s);

    inserAtbottom(s,topEle);
    return;
}

bool checkSorted(stack<int> &s,int maxi){
    
    if(s.empty()){
        return true;
    } 

    int topEle = s.top();
    s.pop();

    if(topEle<maxi){
        maxi = topEle;

        bool agekaans = checkSorted(s,maxi);
        s.push(topEle);
        return agekaans;
    }

    else{
        return false;
    }
   
 
}

void sortedInsert(stack<int> &s,int val){

    if(val>s.top()){
        s.push(val);
        return;
    }

    int topEle = s.top();
    s.pop();

    sortedInsert(s,val);

    s.push(topEle);
    return;
}

int main(){
    
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);


    sortedInsert(s,23);
    print(s);

    // int maxi = INT_MAX;
    // bool ans = checkSorted(s,maxi);
    // string st = ans? "Sorted": "Not Sorted";
    // cout<<st<<endl;
    

    // print(s);
    // cout<<endl;
    // Sreverse(s);
    // print(s);


    // print(s);
    // cout<<endl;
    // inserAtbottom(s,23);
    // print(s);

    // int mid = s.size()/2;
    // printmiddle(s,mid);

    return 0;
}