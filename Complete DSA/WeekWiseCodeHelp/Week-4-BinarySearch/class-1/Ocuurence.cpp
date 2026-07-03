# include<bits/stdc++.h>
using namespace std; 

int binarySearch(vector<int>v,int t){
    int s,e,mid;
    s=0,e=v.size()-1;
    while(s<=e){
        mid = s + (e-s)/2;
        if(v[mid]==t) return mid;
        else if(v[mid]>t) e=mid-1;
        else s=mid+1;
    }
    return -1;
}

int firstoccu(vector<int>v,int t){
    int s,e,mid;
    s=0,e=v.size()-1;
    int ans=0;
    while(s<=e){
        mid = s + (e-s)/2;
        if(v[mid]==t){
            ans = mid;
            e = mid-1;
        }
        else if(v[mid]>t) e=mid-1;
        else s=mid+1;
    }
    return ans;

}

int lastoccu(vector<int>v,int t){
    int s,e,mid;
    s=0,e=v.size()-1;
    int ans=0;
    while(s<=e){
        mid = s + (e-s)/2;
        if(v[mid]==t){
            ans = mid;
            s = mid+1;
        }
        else if(v[mid]>t) e=mid-1;
        else s=mid+1;
    }
    return ans;

}


pair<int,int> bothOcuurence(vector<int>v,int t){
    int s,e,mid;
    s=0,e=v.size()-1;
    pair<int,int>ans;
    int fo = firstoccu(v,t);
    int lo = lastoccu(v,t);
    ans.first=fo;
    ans.second=lo;
    return ans;

}

int main(){
    vector<int>a = {10,20,20,20,30,40,50,60};
    // int focuu = firstoccu(a,20);
    // int locuu = lastoccu(a,20);
    // cout<<focuu<<" "<<locuu<<endl;

    auto ans = bothOcuurence(a,20);
    cout<<ans.first<<" "<<ans.second<<endl;
    

    

 return 0;
}