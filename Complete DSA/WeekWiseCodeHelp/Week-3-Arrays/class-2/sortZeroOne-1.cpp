# include<bits/stdc++.h>
using namespace std; 

void print(int arr[],int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
}

// Using Two pionters
void sort01(vector<int>&v){
    int i =0;
    int j = v.size()-1;

    
}

// counting use
void sortZerOne(int v[],int s){
    int one = 0;
    int zero = 0;

    for(int i=0;i<s;i++){
        if(v[i]==0) zero++;
        else one++;
    }
    fill(v,v+zero,0);
    fill(v+zero,v+s,1);
}


int main(){
    
    vector<int>v = {0,1,1,0,0,1,1,0};

    int arr[] = {0,1,1,0,0,1,1,0};
    // sortZerOne(arr,8);
    // print(arr,8);

    sort(arr,arr+8);
    print(arr,8);
    
 return 0;
}