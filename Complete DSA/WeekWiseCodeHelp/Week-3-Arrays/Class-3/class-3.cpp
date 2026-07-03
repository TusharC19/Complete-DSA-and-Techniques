# include<bits/stdc++.h>
using namespace std; 

int main(){

    // int arr[3][4] = { {1,2,3,4} , {5,6,7,8} , {9,10,11,12}};
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl;
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    // int ar[3][3] = {1,2,3,4,5,6,7,8,9};
   
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<ar[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    //  // lower diagonal print
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(ar[i] == ar[j]) cout<<ar[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // upper diagonal print
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(ar[i] == ar[j]) cout<<ar[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<3;i++){
    //     cout<<ar[i][i]<<" ";
    //     cout<<endl;
    // }

    // row wise input
    int a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }




    
   

    
 
 return 0;
}