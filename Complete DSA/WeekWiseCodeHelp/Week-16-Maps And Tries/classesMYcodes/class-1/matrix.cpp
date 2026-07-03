# include<bits/stdc++.h>
using namespace std; 

void print(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void transpose(vector<vector<int>>&matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main(){
    vector<vector<int>>matrix = {{1,2,3},{4,5,6}};
    print(matrix);
    transpose(matrix);
    cout<<endl;
    print(matrix);


 return 0;
}