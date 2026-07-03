# include<bits/stdc++.h>
using namespace std; 

int sqrt(int n){
    int s=0,e=n;
    long long mid;
    int root = -1;
    while(s<=e){
        mid = s + (e-s)/2;

        long long p = mid*mid;
        if(p<=n){
            root = mid;
            s = mid+1;
        }
        else e = mid - 1;

    }
    return root;
}


int main(){
    int n = 72;
    int ans = sqrt(n);
    cout<<ans<<endl;
 return 0;
}