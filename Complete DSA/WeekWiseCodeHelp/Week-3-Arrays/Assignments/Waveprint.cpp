# include<bits/stdc++.h>
using namespace std; 

int main(){

  vector<vector<int>>v = {{1,2,3,4},
                          {5,6,7,8},
                          {9,10,11,12}
                        };

  int r = v.size();
  int c = v[0].size();

  // cout<<r<<" "<<c<<endl;

  for(int st=0;st<c;st++){
    // even case
    if((st&1) == 0){
      for(int i=0;i<r;i++){
        cout<<v[i][st]<<" ";
      }
    }
    else{
      // odd case
      for(int i=r-1;i>=0;i--){
        cout<<v[i][st]<<" ";
      }
    }
  }



 return 0;
}