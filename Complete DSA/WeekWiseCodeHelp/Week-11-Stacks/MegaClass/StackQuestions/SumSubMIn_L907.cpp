# include<bits/stdc++.h>
using namespace std;

vector<int> nsei(vector<int>&a){
    int n = a.size();

    stack<int>s;
    s.push(-1);

    vector<int>b;

   for(int i=n-1;i>=0;i--){
    int element = a[i];

    while(!s.empty() && a[s.top()]>element && s.top()!= -1){
        s.pop();

    }

    b.push_back(s.top());
    s.push(i);
    }

    return b;
}

vector<int> psei(vector<int>&a){
    int n = a.size();

    stack<int>s;
    s.push(-1);

    vector<int>b;

   for(int i=0;i<n;i++){
    int element = a[i];

    while(!s.empty() && a[s.top()]>element && s.top()!= -1){
        s.pop();

    }
    b.push_back(s.top());
    s.push(i);
    }

    return b;
}

int main(){

    vector<int>a = {3,1,2,4};
    auto next = nsei(a);
    reverse(next.begin(),next.end());
    for(int i=0 ;i<next.size();i++){
        if(next[i]==-1) next[i] = next.size();
    }
   
    auto prev = psei(a);

    int sum = 0;
    for(int i=0;i<next.size();i++){
        int rkl = next[i] - i;
        int lkl = i - prev[i];
        sum += (rkl*lkl);
    }

    cout<<sum<<endl;

  



    return 0;
} 