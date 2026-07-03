// 17-03-25 

# include<bits/stdc++.h>
using namespace std; 

int main(){
    int a[] = {0,1,1,1,0,0};
    for(int i=0;i< 8;i++){
        if(a[i]==0) a[i] = 1;
        else a[i] = 0;
    }

    for(int i: a) cout<<i<<" ";

 return 0;
}