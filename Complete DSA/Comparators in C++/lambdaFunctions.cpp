# include<bits/stdc++.h>
using namespace std; 

void print(vector<int>&a){
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int>a = {3,5,2,8,1};
    auto mylambda = [&](int a,int b){
        return a>b;
    };
    sort(begin(a),end(a),mylambda);
    print(a);
 return 0;
}