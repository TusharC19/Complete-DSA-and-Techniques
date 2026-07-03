# include<bits/stdc++.h>
using namespace std; 

void merge(vector<int>&v,int s,int e,int mid){

    //create left and right arrays
    int leftlen = mid-s+1;
    int rightlen = e-mid;

    vector<int>a(leftlen);
    vector<int>b(rightlen);

    // copy values of two breaked part
    int idx=s; // main arr index

    for(int i=0;i<leftlen;i++){
        a[i] = v[idx];
        idx++;
    }
    idx = mid+1;

    for(int i=0;i<leftlen;i++){
        b[i] = v[idx];
        idx++;
    }

    // merge sort logic
    int i=0,j=0;
    int mainArrindex=s;

    while(i<leftlen && j<rightlen){
        if(a[i]<b[j]){
            v[mainArrindex] = a[i];
            mainArrindex++,i++; 
        }
        else{
            v[mainArrindex] = b[j];
            mainArrindex++,j++; 
        }
    }

    while(i<leftlen){
        v[mainArrindex] = a[i];
        i++,mainArrindex++;
    }

    while(j<rightlen){
        v[mainArrindex] = b[j];
        mainArrindex++,j++;
    }

    
}


void mergeSort(vector<int>&v,int s,int e){
   
    // base case
    if(s>=e) return;

    // int mid nikala
    int mid = s+(e-s)/2;

    // left part sort by break by recursion
    mergeSort(v,s,mid);

    // right part sort by break by recursion
    mergeSort(v,mid+1,e);

    // merge kardiya two sorted arrays ko
    merge(v,s,e,mid);
}



int main(){
    
    vector<int>arr = {10,80,50,110,30,120,20,60,40,70};
    int n= arr.size();
    int s=0,e=n-1;

    for(auto i: arr) cout<<i<<" ";
    cout<<endl;

    mergeSort(arr,s,e);

    for(auto i: arr) cout<<i<<" ";
    cout<<endl;



    // int* a = new int[10];
    // for(int i=0;i<10;i++){
    //     cout<<a[i]<<" ";
    // }
    


 return 0;
}