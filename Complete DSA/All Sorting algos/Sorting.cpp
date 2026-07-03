# include<bits/stdc++.h>
using namespace std; 

void printArr(vector<int>&a){
    for(int i: a) cout<<i<<" ";
}

void bubbleSort(vector<int>&a){
    int n = a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

void selectionSort(vector<int>&a){
    int n = a.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]) swap(a[i],a[j]);
        }
    }
}

void insertionSort(vector<int>&a){
    int n = a.size();
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(a[j]>key && j>=0){
            a[j+1] = a[j];
            a[j] = key;
            j--;
        }
    }
}


int main(){
    vector<int>a ={5,8,3,9,4,6,6,2};
    // bubbleSort(a);
    // selectionSort(a);
    insertionSort(a);



    printArr(a);









 return 0;
}