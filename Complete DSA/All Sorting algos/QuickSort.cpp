# include<bits/stdc++.h>
using namespace std; 

//quick sort algo--------------------------------------
int partition(vector<int>&a,int l,int h){
    int n = a.size();
   
    //pick random pivot inside [l, h]
    int pivotIdx = l + rand() % (h - l + 1);
    swap(a[pivotIdx],a[l]);

    // choose pivot 
    int pivot = a[l];
    int i=l,j=h;

    // since duplicates can be there so 
    while(i<j){
        while(i<h && a[i]<=pivot) i++;
        while(j>l && a[j]>pivot) j--;
        if(i<j) swap(a[i],a[j]);
    }
    // till here j>i ho chuka hoga so
    // so swap a[j] so that a[l] comes to it original postition
    swap(a[j],a[l]);
    return j;
}

void qs(vector<int>&a,int l,int h){
    if(l>=h) return;
    int pivotIdx = partition(a,l,h);
    qs(a,l,pivotIdx-1);
    qs(a,pivotIdx+1,h);
}

// int main(){
//     vector<int>a = {1,4,3,6,8,4,9,2,5};
//     qs(a,0,a.size()-1);
//     for(int i:a) cout<<i<<" ";cout<<endl;
//  return 0;
// }


//------------------------------------------------
// for quick select algo using loop
int pivot(vector<int>&a,int l,int h){
    int n = a.size();
    int idx = l + rand() %(h-l+1);
    swap(a[l],a[idx]);
    int pivot = a[l];
    
    int i=l+1,j=h;
    while(i<j){
        // remain in subarry range
        while(i<=h && a[i]>=pivot) i++;
        while(j>=l && a[j]<pivot) j--;
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[j],a[l]);
    return j;
}

// it is using loop
int quickSelect(vector<int>&a,int k){
    int n = a.size();
    int l=0,h=a.size()-1;
    int pidx = 0;

    while(true){
        pidx = pivot(a,l,h);

        if(pidx==k-1) break;

        else if(pidx>k-1){ // 4th largest
            h = pidx-1;
        }
        else{
            l = pidx+1;
        }
    }
    
    return pidx;
    
}


int main() 
{ 
    
   vector<int>a = {1,4,2,6,9,3,8};
   int k = 3; //kthLargest
   int idx = quickSelect(a,k);
   cout<<a[idx]<<endl;

}

/*
GPT Answer
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int h) {
    int idx = l + rand() % (h - l + 1);
    swap(a[l], a[idx]); 
    int pivot = a[l];

    int i = l, j = h;
    while (i < j) {
        while (i <= h && a[i] <= pivot) i++;
        while (j >= l && a[j] > pivot) j--;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j; // pivot index
}

int quickSelect(vector<int>& a, int l, int h, int k) {
    if (l <= h) {
        int p = partition(a, l, h);
        if (p == k) return a[p];
        else if (p > k) return quickSelect(a, l, p - 1, k);
        else return quickSelect(a, p + 1, h, k);
    }
    return -1; // shouldn't reach here
}

int main() {
    vector<int> a = {7, 2, 9, 4, 1, 6};

    int n = a.size();

    // 3rd smallest → index 2 (0-based)
    int thirdSmallest = quickSelect(a, 0, n - 1, 2);

    // 2nd largest → index n-2
    int secondLargest = quickSelect(a, 0, n - 1, n - 2);

    cout << "3rd Smallest = " << thirdSmallest << endl;
    cout << "2nd Largest = " << secondLargest << endl;
}


*/ 