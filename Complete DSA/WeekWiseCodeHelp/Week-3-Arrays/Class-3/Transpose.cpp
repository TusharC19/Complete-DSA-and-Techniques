# include<bits/stdc++.h>
using namespace std; 

void transpose(int arr[][3],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=i;j<c;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void print(int arr[][3],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int arr[3][3] = {10,11,12,30,31,32,1,2,3};
    print(arr,3,3);
    cout<<endl;
    transpose(arr,3,3);
    cout<<endl;
    print(arr,3,3);

    
 return 0;
}