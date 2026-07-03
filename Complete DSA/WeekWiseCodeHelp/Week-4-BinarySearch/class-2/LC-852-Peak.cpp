# include<bits/stdc++.h>
using namespace std; 

int peakIndex(vector<int>v){
    int s=0,e=v.size()-1,mid;
    int ansIndex = -1;
    while(s<=e){
        mid = s +(e-s)/2;
        // line A
        if(v[mid]<v[mid+1]) s = mid+1;

        else{
            // line B
            ansIndex = mid;
            e = mid-1;
        }
    }
    return ansIndex;
}


int main(){
    vector<int>a = {10,11,9,8,7,6,5,4,3,2,1};
    int ans = peakIndex(a);
    cout<<ans<<endl;
 return 0;
}                