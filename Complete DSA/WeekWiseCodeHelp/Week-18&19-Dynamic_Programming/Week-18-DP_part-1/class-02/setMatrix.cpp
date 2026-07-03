# include<bits/stdc++.h>
using namespace std; 


void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>coordinats;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == 0 ){
                    vector<int>a(2,-1);
                    a[0] = i;
                    a[1] = j;
                    coordinats.push_back(a);
                }
            }
        }

        for(auto&it : coordinats){
            int row = it[0];
            int col = it[1];
            // make row ele 0
            for(int i=0;i<rows;i++){
                matrix[i][col] = 0;
            }
            // make col ele zero
            for(int j=0;j<cols;j++){
                matrix[row][j] = 0;
            }

        }
    }

void printMat(vector<vector<int>>&matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>>matrix = {{0,1,0},{1,1,1},{1,1,1}};
    printMat(matrix);
    setZeroes(matrix);
    cout<<endl;
    printMat(matrix);



    
 return 0;
}