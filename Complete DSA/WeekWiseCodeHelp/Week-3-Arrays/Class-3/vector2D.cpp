# include<bits/stdc++.h>
using namespace std; 

bool find(vector<vector<int>>&arr,int target){
    
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if((arr[i][j]) == target) return true;
        }

    }
    // dono loop traverse kar chuke ho
    return false;
}

void rowSum(vector<vector<int>>&arr){
    
    int totalSum = 0;
    for(int i=0;i<arr.size();i++){
        int sum = 0;
        for(int j=0;j<arr[0].size();j++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
        totalSum += sum;

    }
    // dono loop traverse kar chuke ho
    cout<<totalSum<<endl;
}

int diagonalSum(vector<vector<int>>&arr){
    int sum = 0;
    for(int i=0;i<arr.size();i++){
       if(arr[i][i]) sum+= arr[i][i];
        
    }
    // dono loop traverse kar chuke ho
    return sum;
}


int main(){
    
    // vector<vector<int>>arr(4,vector<int>(3,-1));

    // int rowsize = arr.size();
    // int colsize = arr[0].size();

    int arr[3][3] = {1,2,3,4,5,6,7,8,9};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    // cout<<find(arr,14)<<endl;
    // rowSum(arr);

    // int ans = diagonalSum(arr);
    // cout<<ans<<endl;


 return 0;
}