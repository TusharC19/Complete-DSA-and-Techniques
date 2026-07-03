# include<bits/stdc++.h>
using namespace std; 

int binarySearch(int s,int e,int target,vector<int>&v){
    int mid;

    while (s<=e)
    {
        mid = s+(e-s)/2;

        if(v[mid]==target) return mid;
        else if(v[mid]>target) e=mid-1;
        else s = mid+1;
    }
    return -1;
    
}

// pivot index har baar hoga 
// except single element
int findPivot(vector<int>a){
    int s=0,e=a.size()-1,mid;

    while (s<=e)
    {   
        mid= s+(e-s)/2;

        // single case
        if(s==e) return s;

        // pivot pe hi ho
        if(mid+1 <a.size() && a[mid]>a[mid+1]) return mid;
        // kab left kab right
        // line B
        if(mid-1 >=0 && a[mid]<a[s] ) e = mid-1; 
        // line A
        else{
            s = mid+1;
        }
        
    }
    return -1;
    
}

// element ho bhi sakta hai aur nhi bhi
int search(vector<int>a,int target){

    int pivot = findPivot(a);

    int n = a.size();
    // line A
    if(target>=a[0] && target<=a[pivot]){
        return binarySearch(0,pivot,target,a);
    }
    // line B me search
    else{
        // target>=a[pivot+1] && target<=a[n-1]
        return binarySearch(pivot+1,n-1,target,a);
    }
    // jab element hi nhi mila 
    // toh pivot index = -1 hoga
    // so koi bhi cndition satisfy nhi hogi 
    // hence return -1
    return -1;

}


int main(){
    vector<int>a = {4,5,6,7,0,1,2};
    int target = 0;
    int ans = search(a,target); 
    // cout<<ans<<endl;
    cout<<sqrt(54)<<endl;

 return 0;
}