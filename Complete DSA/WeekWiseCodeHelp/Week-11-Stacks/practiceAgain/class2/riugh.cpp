# include<bits/stdc++.h>
using namespace std; 

bool checkSorted(stack<int> &s,int mini){

    if(s.empty()){
        cout<<"sorted"<<endl;
        return true;
    }

    int topEle = s.top();
    s.pop();

    if(topEle>mini){

        mini = topEle;
        bool agekaans = checkSorted(s,mini);

        s.push(topEle);
        return agekaans;
    }

    else{
        return false;
    }
}

void sortedInsert(stack<int>&s,int val){

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

    sortedInsert(s,23);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    
     return 0;
}