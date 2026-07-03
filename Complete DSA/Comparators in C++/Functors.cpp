# include<bits/stdc++.h>
using namespace std; 

void print(vector<int>&a){
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    cout<<endl;
}

class mycmp{
    public:
    bool operator()(int a,int b){
        return a>b;
    }
};

int main(){
    vector<int>a = {3,5,2,8,1};
    sort(begin(a),end(a),mycmp());
    print(a);
    
 return 0;
}


