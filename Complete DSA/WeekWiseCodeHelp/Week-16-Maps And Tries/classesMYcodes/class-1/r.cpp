# include<bits/stdc++.h>
using namespace std; 

int main(){
    // priority_queue<float,vector<float>,greater<float>>pq;
    priority_queue<float>pq;
    pq.push(0.7);
    pq.push(0.66);
    pq.push(0.6);
    pq.push(0.62);

    int i = 1;
    while(i<=3){ 
        pq.pop();
        i++;
    }
    cout<<pq.top()<<endl;

 return 0;
}