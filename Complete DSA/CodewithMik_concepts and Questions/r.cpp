# include<bits/stdc++.h>
using namespace std; 


// a.size()<=100
// a[i].size()<=100
// q.size()<=100
// kth<=n
// trim<=a[i].size()

#define p pair<int,int>

vector<int> solve(vector<string>&a,vector<vector<int>>&q){
    vector<int>ans;
    int n=a.size(),m=q.size();
    // priority_queue<vector<pair<int,int>>,pair<int,int>,greater<int>>pq;
    for(auto&it:q){
        priority_queue<p,vector<p>,greater<p>>pq;
        int kth=it[0],trim=it[1];
        for(int i=0;i<n;i++){
            string s=a[i];
            int len=s.size();
            int val=(len==trim)?stoi(s):stoi(s.substr(len-trim));
            pq.push({val,i});
        }

        int topop=kth-1;
        while(topop--) pq.pop();
        ans.push_back(pq.top().second);
        
    }

    return ans;
}



int main(){
    vector<string>a={"102","473","251","814"};
    vector<vector<int>>q={{1,1},{2,3},{1,2},{2,2}};
    auto ans=solve(a,q);

    for(int i:ans) cout<<i<<" ";

 return 0;
}