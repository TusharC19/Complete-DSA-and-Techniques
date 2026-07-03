# include<bits/stdc++.h>
using namespace std; 

void printArr(int a[],int s,int idx){
    if( idx==s) return ;
    cout<<a[idx]<<" ";
    printArr(a,s,idx+1);

    return;

}


void Reverseprint(int a[],int s,int idx){
    if( idx==s) return ;
   
    Reverseprint(a,s,idx+1);
    cout<<a[idx]<<" ";
    return;

}

bool Search(int a[],int s,int i,int t){
    // two base cases
    if(i>=s){
        return false;
    }
    if(a[i]==t) return true;

    bool ans = Search(a,s,i+1,t);
    return ans;
}

void searchMAX(int a[],int s,int i,int &maxi){
    if(i >= s) return;

    // ek case mera baki recursion ka
    maxi = max(maxi,a[i]);
    // baki recursion
    searchMAX(a,s,i+1,maxi);
    return;
}

void printOdds(int a[],int i,int s){
    if(i>=s) return ;

    if(a[i]%2 != 0) cout<<a[i]<<" ";
        
    printOdds(a,i+1,s);
    return ;
    
}

void printEvens(int a[],int i,int s,vector<int>&ans){
    if(i>=s) return ;

    if(a[i]%2 == 0) ans.push_back(a[i]);
        
    printEvens(a,i+1,s,ans);
    return ;
    
}

int binarySearch(int a[],int s,int e,int t){

    if(s>e) return -1;
    int mid = s + (e-s)/2;
    if(a[mid] == t) return mid;
    else if(a[mid]<t) binarySearch(a,mid+1,e,t);
    else binarySearch(a,s,mid-1,t);

}

void printDigits(int n){
    if(n==0) return;

    int digit = n%10;
    n /= 10;
    printDigits(n);
    cout<<digit<<" ";
}



int main(){
    // int arr[] = {1,2,3,4,5,6};
    // printArr(arr,6,0);
    // int a[] = {12,3,56,77,8,34};
    // bool ans = Search(a,6,0,33);
    // cout<<ans<<endl;

    // int maxi = INT_MIN;
    // searchMAX(a,6,0,maxi);
    // cout<<maxi<<endl;

    // int mini = INT_MAX;
    // searchMIN(a,6,0,mini);
    // cout<<mini<<endl;

    
    // printOdds(arr,0,6);
    // cout<<endl;
    // vector<int>ans;
    // printEvens(arr,0,6,ans);
    // for(int i: ans) cout<<i<<" ";

    // int a[] = {1,2,3,4,5,6};
    // int ans = binarySearch(a,0,5,20);
    // cout<<ans<<endl;

    printDigits(1234);


 return 0;
}