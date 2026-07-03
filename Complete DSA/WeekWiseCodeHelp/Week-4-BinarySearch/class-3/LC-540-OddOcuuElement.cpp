# include<bits/stdc++.h>
using namespace std; 

int findoddOcc(vector<int>&a){
    int n=a.size();
    int s=0,e=n-1,mid;

    while(s<=e){
        mid = s+(e-s)/2;

        // single element
        if(s==e){
            return s;
        }
        // duplicate not exist
        if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1] && mid-1>=0 && mid+1<n){
            return mid;
        }
        // duplicate exists in left index
        if(a[mid] == a[mid-1] && mid-1>=0){
            if((mid-1)&1) {e = mid-2;}  // odd index
            else {s = mid+2;}  // even index
        }
        // duplicate exists in right part
        if(a[mid]==a[mid+1] && mid+1<n){
            if((mid)&1) { e = mid-2;}  //odd index
            else {s = mid+2;} // even index
        }

    }
    return -1;
}



int main(){
    // vector<int>a = {1,1,2,2,3,3,4,4,5,6,6,4,4,2,2};
    // vector<int>a = {1,1,2,2,3,3,4,5,5,3,3};
    vector<int>a = {2,2,3,4,4};

    int ans = findoddOcc(a);
    cout<<"ans idx: "<<ans<<endl;
    cout<<"ans element: "<<a[ans]<<endl;


    
 return 0;
}