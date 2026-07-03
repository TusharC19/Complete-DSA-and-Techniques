# include<bits/stdc++.h>
using namespace std; 
int BS(vector<int>& arr, int s, int e, int target) {

        int mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (target == arr[mid])
                return mid;

            else if (target > arr[mid])
                s = mid + 1;

            else
                e = mid - 1;
        }

        return -1;
    }

    int pivot(vector<int>& arr) {
        int n = arr.size();
        int s = 0, e = n - 1;
        int mid;
        

        while (s <= e) {
            mid = s + (e - s) / 2;

            if(s==e) return s;  // ye important hai

            if (mid + 1 < n && arr[mid] > arr[mid + 1])
                return mid;
            
            // not needed - but coorect
            // if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
            //     return mid - 1;

            // line B
            if (arr[mid] < arr[0]) {
                e = mid - 1;
            }
            // line A
            else
                s = mid + 1;

            
        }

        return -1;
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int pivotIdx = pivot(arr);
        cout<<pivotIdx<<endl;

        int ans;
        // line A
        if (target >= arr[0] && target <= arr[pivotIdx]) {
            // apply BS
            ans = BS(arr, 0, pivotIdx, target);

        }
        // line B
        else{
            // target >= arr[pivotIdx] && target <= arr[n - 1]
            // apply BS
            ans = BS(arr, pivotIdx + 1, n - 1, target);
        }

        return ans;
    }

int main(){
    
 return 0;
}