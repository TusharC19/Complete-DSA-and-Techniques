# include<bits/stdc++.h>
using namespace std; 

int bsmissingNum(vector<int>v){
    int s,e,mid;
    s=0,e=v.size()-1;
    int ans = -1;
    while(s<=e){
        mid = s + (e-s)/2;
        if(v[mid]-mid==0){
            s=mid+1;
        }
        if(v[mid]-mid != 0){
            ans = mid;
            e = mid-1;
        }
    }
    if(ans==-1) return v.size();
    else return ans;
}

int main(){
    vector<int>a = {0,1,2,3};
    auto ans = bsmissingNum(a);
    cout<<ans<<endl;

 return 0;
}