# include<bits/stdc++.h>
using namespace std; 

int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();

        int s = 0, e = n - 1, mid;
        int idx = -1;

        while (s <= e) {
            mid = s + (e - s) / 2;

            if (mid + 1 < n && mid - 1 >= 0 && arr[mid] > arr[mid + 1] &&
                arr[mid] > arr[mid - 1]) {
                idx = mid;
                s = mid + 1;
            }
            // left part
            // also mid == 0 toh yha mid-1 invalid access le rha tha
            // i.e arr[mid]>arr[mid+1] ye invalid hai

            else if (mid + 1 < n && arr[mid+1] > arr[mid])
                s = mid + 1;

            // right part
            // also mid == n-1 toh yha mid+1 invalid access le rha tha
            // i.e arr[mid]>arr[mid+1] ye invalid hai
            else if(mid-1>=0 && arr[mid-1]>arr[mid])
                e = mid-1;
                
        }

}



int main(){
    vector<int>a = {0,10,9,8,7,6,5,2};
    auto ans = peakIndexInMountainArray(a);
    cout<<a[ans]<<endl;

 return 0;
}