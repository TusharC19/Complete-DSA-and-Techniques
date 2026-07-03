# include<bits/stdc++.h>
using namespace std; 

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

vector<int> slidingWindow(queue<int>&q){
    vector<int>ans;

    int n = q.size();
    int m = n/2;
    cout<<m<<endl;

    queue<int>q1;
    for(int i=0;i<m;i++){
        int ele = q.front();
        q.pop();
        q1.push(ele);
    }
    cout<<"q1 is"<<endl;
    print(q1);


    for(int i=0;i<m;i++){
        int e1 = q1.front();
        ans.push_back(e1);
        q1.pop();
        int e2 = q.front();
        ans.push_back(e2);
        q.pop();
    }

    return ans;
}

void RearrangePattern(queue<int>&q){

    int n = q.size();
    int m = n/2;
    cout<<m<<endl;

    queue<int>q1;
    for(int i=0;i<m;i++){
        int ele = q.front();
        q.pop();
        q1.push(ele);
    }
    cout<<"q1 is"<<endl;
    print(q1);


    for(int i=0;i<m;i++){
        int e1 = q1.front();
        q.push(e1);
        q1.pop();
        int e2 = q.front();
        q.push(e2);
        q.pop();
    }

}

int main(){
    queue<int>q;
    q.push(20);
    q.push(40);
    q.push(80);
    q.push(10);
    q.push(30);
    q.push(50);


    // print(q);
    // auto ans = slidingWindow(q);
    // for(auto i: ans){
    //     cout<<i<<" ";
    // }
    
    print(q);
    RearrangePattern(q);
    print(q);
    


 return 0;
}