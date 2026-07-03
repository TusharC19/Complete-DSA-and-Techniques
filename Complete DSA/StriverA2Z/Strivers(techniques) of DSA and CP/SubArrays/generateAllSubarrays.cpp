# include<bits/stdc++.h>
using namespace std; 

int main(){
    vector<int>a = {1,2,3};
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
        // cout<<endl;
    }
 return 0;
}