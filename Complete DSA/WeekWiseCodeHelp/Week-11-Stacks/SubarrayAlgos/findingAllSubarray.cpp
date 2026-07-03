# include<bits/stdc++.h>
using namespace std; 

void allSubarr(vector<int> &v){
    int n = v.size();

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<v[k]<<" ";
            }
            cout<<endl;
        }
    }
}


int main(){
    
    vector<int>v = {1,2,3,4};
    allSubarr(v);

    
 return 0;
}