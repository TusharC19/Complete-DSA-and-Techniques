# include<bits/stdc++.h>
using namespace std; 

int dearrangements(int n){

    if(n==1) return 0;
    if(n==2) return 1;

    int permutationsCount;

    permutationsCount = (n-1) * (dearrangements(n-2) + dearrangements(n-1));

    return permutationsCount;
}


int main(){
    int n = 4;
    int ans = dearrangements(n);
    cout<<ans<<endl;

    
 return 0;
}