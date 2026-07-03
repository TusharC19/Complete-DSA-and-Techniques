# include<bits/stdc++.h>
using namespace std; 

int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
    int n = original.size();
    int r = bounds.size();
    int c = bounds[0].size();

    int mini = INT_MAX;
    for(auto it: bounds){
        int size = it.size();
        if(it[0]==it[size-1]){
            return 0;
        }
        else{
        int diff = (it[size-1]-it[0])+1;
        mini = min(mini,diff);
        }
        // cout<<mini<<endl;
    }


    return mini;
}

int main(){
    vector<vector<int>>b = {{1,1},{2,3},{3,3},{2,3}};
    vector<int>a = {1,2,3,4};
    int ans = countArrays(a,b);
    cout<<"ans is: "<<ans<<endl;


 return 0;
}