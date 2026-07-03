# include<bits/stdc++.h>
using namespace std; 

int firstOcuu(vector<int>&arr,int target){
    int n = arr.size();
    int s =0,e=n-1,mid;

    int idx = 0;
    while(s<=e){
        mid = s + (e-s)/2;
        int ele = arr[mid];

        if(ele == target){
            idx = mid;
            e = mid-1;
            
        }

        else if(ele<target) s = mid+1;

        else e = mid-1;
            
    }

    return idx;
    

}

int lastOcuu(vector<int>&arr,int target){
    int n = arr.size();
    int s =0,e=n-1,mid;

    int idx = 0;
    while(s<=e){
        mid = s + (e-s)/2;
        int ele = arr[mid];

        if(ele == target){
            idx = mid;
            s = mid+1;
            
        }

        else if(ele<target) s = mid+1;

        else e = mid-1;
            
    }

    return idx;
    

}

vector<int> bothOcuu(vector<int>&arr,int target){
    int firstidx = firstOcuu(arr,target);
    int lastidx = lastOcuu(arr,target);

    return {firstidx,lastidx};
}


int missingNum(vector<int>&arr){
    int n = arr.size();
    int s =0,e=n-1,mid; 
    sort(arr.begin(),arr.end());

    int num = -1;
    // while(s<=e){
    //     mid = s + (e-s)/2;
    //     int ele = arr[mid];

    //     if(ele != mid){
    //         num = mid;
    //         e = mid-1;
    //     }

    //     else s = mid+1;
            
    // }

    // logic 2
    while(s<=e){
        mid = s + (e-s)/2;
        int ele = arr[mid];

        int diff = ele-mid;

        if(diff==1){
            num = mid;
            e = mid-1;
        }
        
        else s= mid+1;


    }

    return num;
}

int main(){
    vector<int>a = {3,0,1};
    auto ans = missingNum(a);
    cout<<ans<<endl;
    // cout<<ans[0]<<" "<<ans[1]<<endl;

 return 0;
}