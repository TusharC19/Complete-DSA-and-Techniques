# include<bits/stdc++.h>
using namespace std; 

void print(vector<int>&v){
    int n = v.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<v[i]<<","<<v[j]<<" ";
        }
        cout<<endl;
    }
}

pair<int,int> twoSum(vector<int>&v,int t){
    int n = v.size();
    pair<int,int>p;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ans = v[i]+v[j];
            if(ans == t){
                p.first = v[i];
                p.second = v[j];
            }
        }
        
    }

    return p;
    
}



int main(){

    vector<int>v = {10,5,20,15,30};
    auto ans = twoSum(v,35);
   

 return 0;
}