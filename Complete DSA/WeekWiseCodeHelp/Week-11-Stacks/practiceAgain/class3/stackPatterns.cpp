# include<bits/stdc++.h>
using namespace std; 

void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

vector<int> nextSmallerEle(vector<int> v){
    int n = v.size();
    vector<int>ans;

    stack<int>s;
    s.push(-1);

    for(int i=n-1;i>=0;i--){

        int m = v[i];

        while(m<s.top()){
            s.pop();
        }

        ans.push_back(s.top());
        s.push(m);
    }

    return ans;
}

vector<int> nextGreaterEle(vector<int> v){
    int n = v.size();
    vector<int>ans;

    stack<int>s;
    s.push(10000);

    for(int i=n-1;i>=0;i--){

        int m = v[i];

        while(m>s.top()){
            s.pop();
        }

        ans.push_back(s.top());
        s.push(m);
    }

    return ans;
}

vector<int> prevSmallerEle(vector<int> v){
    int n = v.size();
    vector<int>ans;

    stack<int>s;
    s.push(-1);

    for(int i=0;i<n;i++){

        int m = v[i];

        while(m<s.top()){
            s.pop();
        }

        ans.push_back(s.top());
        s.push(m);
    }

    return ans;
}

vector<int> prevGreaterEle(vector<int> v){
    int n = v.size();
    vector<int>ans;

    stack<int>s;
    s.push(10000);

    for(int i=0;i<n;i++){

        int m = v[i];

        while(m>s.top()){
            s.pop();
        }

        ans.push_back(s.top());
        s.push(m);
    }

    return ans;
}


int main(){
    
    vector<int>v = {8,4,6,2,3};

    auto ans = nextGreaterEle(v);

    reverse(ans.begin(),ans.end());

    print(ans);


 return 0;
}