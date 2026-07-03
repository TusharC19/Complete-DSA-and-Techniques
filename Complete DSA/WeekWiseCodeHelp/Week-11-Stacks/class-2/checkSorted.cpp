# include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

bool checKSorted(stack<int>&s,/*int minn*/int maxx){
    
    /// base case
    if(s.empty()){
        return true;
    }
    
    
    int topelement = s.top();
    s.pop();

    if(topelement<maxx){
        // then we can check further
        maxx = topelement;
        // s.pop();
        // checKSorted(s,maxx);
        bool agekaans = checKSorted(s,maxx);
        // also backtrack karte ja sakte hai
        s.push(topelement);
        return agekaans;
    }

    else {
        // no need to check further
        return false;
    }
  

}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    

    int maxx = INT_MAX;
    // int maxx = INT_MIN;

    bool ans = checKSorted(s,maxx);
    if(ans) cout<<"sorted"<<endl;
    else cout<<"Not sorted"<<endl;



    return 0;
}