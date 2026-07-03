# include<bits/stdc++.h>
using namespace std; 

bool searchMatrix(  vector<vector<int>>&v,int t){
    int r=v.size(),c=v[0].size();
    int ele=r*c;
    int s=0,e=ele-1,mid;

    while(s<=e){
        mid = s+(e-s)/2;
        // mid ka use krke row and col index nikalo
        int rowIndex=mid/c;
        int colIndex=mid%c;

        if(v[rowIndex][colIndex] == t){
            return true;
        }
        else if(v[rowIndex][colIndex]<t) s=mid+1;
        else e = mid-1;
    }
    return false;
}




int main(){

    vector<vector<int>>v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    
    string ans = searchMatrix(v,23) ? "yes" : "no";
    cout<<ans<<endl;

    
 return 0;
}