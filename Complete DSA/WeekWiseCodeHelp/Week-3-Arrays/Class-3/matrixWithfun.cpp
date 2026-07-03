# include<bits/stdc++.h>
using namespace std; 

bool find(int a[][3],int r,int c,int target){
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if((a[i][j]) == target) return true;
        }

    }
    // dono loop traverse kar chuke ho
    return false;
}

int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    auto ans = find(arr,3,3,11);
    cout<<ans<<endl;










 return 0;
}