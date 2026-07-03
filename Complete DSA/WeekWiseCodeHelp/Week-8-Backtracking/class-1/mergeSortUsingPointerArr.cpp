# include<bits/stdc++.h>
using namespace std; 


void merge(int *arr,int s,int e,int mid){   
    
    int leftlen = mid-s+1;
    int rightlen = e-mid;

    // two arrays made
    int*a = new int[leftlen];
    int*b = new int[rightlen];

    // copy values in arrays
    int idx = s;
    
    for(int i=0;i<leftlen;i++){
        a[i] = arr[idx];
        idx++;
    }

    idx = mid+1;

    for(int j=0;j<rightlen;j++){
        b[j] = arr[idx];
        idx++;
    }

    // now merge two sorted arrays

    int index = s;
    int i=0,j=0;

    while(i<leftlen && j<rightlen){
        if(a[i]<b[j]){
            arr[index] = a[i];
            i++,index++;
        }
        else{
            arr[index] = b[j];
            j++,index++;
        }
    }
    // ho sakta hai ki arr bacha ho

    while(i<leftlen){
        arr[index] = a[i];
        i++,index++;
    }

    while(j<rightlen){
        arr[index] = b[j];
        j++,index++;
    }

    delete a;
    delete b;
}

void mergeSort(int *arr,int s,int e){

    if(s>=e) return ;
    
    int mid = s+(e-s)/2;

    mergeSort(arr,s,mid);

    mergeSort(arr,mid+1,e);

    merge(arr,s,e,mid);
}


int main(){
    int a[] = {10,80,110,90,50,30};
    int size = 5;
    mergeSort(a,0,5);
    for(int i: a) cout<<i<<" ";





 return 0;
}