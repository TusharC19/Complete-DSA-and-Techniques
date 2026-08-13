# include<bits/stdc++.h>
using namespace std; 

void leftRotate(vector<int>&a,int k){
    // Left rotate by k

    // Step 1: reverse first k

    reverse(a.begin(), a.begin() + k);

    // Step 2: reverse remaining n-k

    reverse(a.begin() + k, a.end());

    // Step 3: reverse whole array

    reverse(a.begin(), a.end());

    // Result: {2, 3, 4, 1}
}


void rightRotate(vector<int>&a,int k){
    // Right rotate by k

    // Step 1: reverse last k

    reverse(a.end() - k, a.end());

    // Step 2: reverse first n-k

    reverse(a.begin(), a.end() - k);

    // Step 3: reverse whole array

    reverse(a.begin(), a.end());

    // Result: {4, 1, 2, 3}
}

int main(){
    
    int n = 4, k = 1;

    vector<int> a = {1, 2, 3, 4};

    // leftRotate(a,k);
    // rightRotate(a,k);

    for(int i:a) cout<<i<<" ";
    
 return 0;
}