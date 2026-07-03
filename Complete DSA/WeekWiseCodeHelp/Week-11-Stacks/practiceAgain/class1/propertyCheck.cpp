# include<bits/stdc++.h>
# include<stack>
using namespace std; 

int main(){
    stack<char>s;

    string st = "amitwala";

    for(int i=0;i<st.length();i++){
        char ch = st[i];
        s.push(ch);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }



     return 0;
}