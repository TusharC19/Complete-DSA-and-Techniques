# include<bits/stdc++.h>
using namespace std; 

void pSubSeq(int i,vector<int>&v,vector<int>&a){
    int n = v.size();
    if(i>=n){
        for(int&i:a) cout<<i<<" ";
        cout<<endl;
        return;
    }

    // add kiya
    a.push_back(v[i]);
    // call next
    pSubSeq(i+1,v,a);
    // wapas aya 
    // remove kiya
    a.pop_back();
    // exclude kiya
    pSubSeq(i+1,v,a);

    return;

}



int main(){
    vector<int>v = {3,2,1};
    vector<int>a;
    pSubSeq(0,v,a);
    
 return 0;
}