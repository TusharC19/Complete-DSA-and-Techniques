# include<bits/stdc++.h>
using namespace std;

int main(){
    
    stack<char>s;
    string name = "HelloWorld";

    // insertion in stack
    for(int i=0;i<name.length();i++){
        char ch = name[i];
        s.push(ch);
    }

    /// retreival from stack
    while(!s.empty()){
        cout<<s.top()<<"";
        s.pop();
    }





    return 0;
}