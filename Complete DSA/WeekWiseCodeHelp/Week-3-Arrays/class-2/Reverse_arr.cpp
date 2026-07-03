# include<bits/stdc++.h>
using namespace std; 

// Also by using two pointers


int main(){
    int arr[] = {1,2,3,4,5,6,7};

    reverse(arr,arr+7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

    
 return 0;
}